# --- Modern Git Ergonomics & Defaults ---

[column]
	ui = auto

[branch]
	sort = -committerdate

[tag]
	sort = version:refname

[init]
	defaultBranch = main

[diff]
	algorithm = histogram
	colorMoved = plain
	mnemonicPrefix = true
	renames = true

[merge]
	conflictstyle = zdiff3

[push]
	default = simple
	autoSetupRemote = true
	followTags = true

[fetch]
	prune = true
	pruneTags = true
	all = true

[pull]
	rebase = true

[rebase]
	autoSquash = true
	autoStash = true
	updateRefs = true

[rerere]
	enabled = true
	autoupdate = true

[commit]
	verbose = true

[help]
	autocorrect = prompt

[feature]
	manyFiles = true

[pack]
	writeReverseIndex = true

[maintenance]
	strategy = incremental

[core]
	untrackedCache = true
