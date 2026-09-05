# --- Stacked Git Workflow Aliases ---
# Requires: git-absorb, gh (GitHub CLI), git-interactive-rebase-tool

[sequence]
	editor = interactive-rebase-tool

[alias]
	# Find origin default branch (main, master, etc.)
	default-branch = "!git symbolic-ref refs/remotes/origin/HEAD | sed 's@^refs/remotes/origin/@@'"

	# Find merge base with default branch on origin
	merge-base-origin = "!f() { git merge-base ${1-HEAD} origin/$(git default-branch); }; f"

	# Display the stack of commits/branches from merge-base to current HEAD
	stack = "!f() { \
		BRANCH=${1-HEAD}; \
		MERGE_BASE=$(git merge-base-origin $BRANCH); \
		git log --decorate-refs=refs/heads --simplify-by-decoration --pretty=format:\"%(decorate:prefix=,suffix=,tag=,separator=%n)\" $MERGE_BASE..$BRANCH; \
	}; f"

	# Push the entire stack of branches in topological order (bottom-up) with lease
	push-stack = "!f() { \
		BRANCH=${1-HEAD}; \
		if [ $# -gt 0 ]; then shift; fi; \
		git stack \"$BRANCH\" | awk '{a[NR]=$0} END {for(i=NR; i>0; i--) print a[i]}' | xargs -I {} git push --force-with-lease \"$@\" origin {}; \
	}; f"

	# Interactive rebase of current stack against merge base
	rebase-stack = "!git rebase -i $(git merge-base-origin)"

	# Absorb staged changes into earlier commits in the stack
	absorb-stack = "!git absorb --base $(git merge-base-origin)"

	# Submit or update PRs for every branch in the stack, automatically chaining bases
	pr-stack = "!f() { \
		BASE=$(git default-branch); \
		STACK=$(git stack ${1-HEAD} | awk '{a[NR]=$0} END {for(i=NR; i>0; i--) print a[i]}'); \
		for BRANCH in $STACK; do \
			echo \"==> Creating/updating PR for $BRANCH (base: $BASE)\"; \
			gh pr create --head \"$BRANCH\" --base \"$BASE\" \"$@\" || true; \
			BASE=\"$BRANCH\"; \
		done; \
	}; f"
