# --- Difftastic Structural Diff Aliases ---
# Requires: difft (difftastic)

[alias]
	# `git dlog`: git log with difftastic
	dlog = -c diff.external=difft log --ext-diff

	# `git dshow`: show commit with difftastic
	dshow = -c diff.external=difft show --ext-diff

	# `git ddiff`: diff with difftastic
	ddiff = -c diff.external=difft diff

	# `git dl`: log with patch using difftastic
	dl = -c diff.external=difft log -p --ext-diff

	# `git ds`: show most recent commit with difftastic
	ds = -c diff.external=difft show --ext-diff

	# `git dft`: diff using difftastic
	dft = -c diff.external=difft diff
