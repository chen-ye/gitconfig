# ==============================================================================
# GitHub Integration & Git Town
# ==============================================================================

[git-town]
	sync-feature-strategy = rebase
	code-hosting-platform = github

[credential "https://github.com"]
	helper = 
	helper = !gh auth git-credential

[credential "https://gist.github.com"]
	helper = 
	helper = !gh auth git-credential
