# ==============================================================================
# General Convenience Aliases
# ==============================================================================

[alias]
	root = git-root
	fixupd = "!git log -n 50 --pretty=format:'%h %s' --no-merges | fzf | cut -c -7 | xargs -o git commit --fixup"
	fixtags = fetch origin --tags --force
