#!/bin/bash
#
# git prepare-commit-msg hook for automatically prepending an issue key
# from the start of the current branch name to commit messages.

COMMIT_TYPE=$2
case "$COMMIT_TYPE" in
    merge|commit)
        # Exit if it's a merge or a commit --amend
        exit
        ;;
esac

ISSUE_KEY=$(git branch --show-current 2>/dev/null | grep -o "\([A-Z]\{2,\}-[0-9]\+\)" | head -n 1)
if [ -z "$ISSUE_KEY" ]; then
    # Fallback for detached HEAD or older git
    ISSUE_KEY=$(git branch | grep -o "\* \(.*/\)*[A-Z]\{2,\}-[0-9]\+" | grep -o "[A-Z]\{2,\}-[0-9]\+" | head -n 1)
fi

if [ -z "$ISSUE_KEY" ]; then
    # No issue key in branch, use default message
    exit 0
fi

COMMIT_MSG=$(cat "$1")
case "$COMMIT_MSG" in
    "$ISSUE_KEY"*)
        # Issue key already present
        exit 0
        ;;
    "fixup!"*|"squash!"*)
        # Don't modify fixup or squash messages
        exit 0
        ;;
esac

# Prepend issue key to commit message
TEMP=$(mktemp /tmp/commitmsg-XXXXX)
echo "$ISSUE_KEY: $COMMIT_MSG" > "$TEMP"
cat "$TEMP" > "$1"
rm -f "$TEMP"
