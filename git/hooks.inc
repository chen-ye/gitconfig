# --- Global Config-Based Git Hooks (Git 2.54+) ---

[hook "prepend-jira-issue"]
	event = prepare-commit-msg
	command = ~/Projects/gitconfig/hooks/prepare-commit-msg/prepend-jira-issue.sh
