# ==============================================================================
# Editor, Diff Tools & Merge Tools
# ==============================================================================

[core]
	editor = code --wait --reuse-window

[filter "lfs"]
	clean = git-lfs clean -- %f
	smudge = git-lfs smudge -- %f
	process = git-lfs filter-process
	required = true

[diff]
	tool = vscode

[difftool]
	prompt = false

[difftool "bc"]
	cmd = bcomp
	trustExitCode = true

[difftool "vscode"]
	cmd = code --wait --reuse-window --diff $LOCAL $REMOTE

[difftool "difftastic"]
	cmd = difft "$LOCAL" "$REMOTE"

[mergetool "smerge"]
	cmd = smerge mergetool \"$BASE\" \"$LOCAL\" \"$REMOTE\" -o \"$MERGED\"
