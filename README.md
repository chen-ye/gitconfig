# gitconfig

Modular, opinionated Git configurations, stacked diff workflows, difftastic integration, and config-based hooks.

Designed to be composable so developers can import the entire configuration or cherry-pick specific modules.

---

## Quick Start

### 1. Clone the repository

```bash
git clone https://github.com/chen-ye/gitconfig.git ~/Projects/gitconfig
```

### 2. Include in your `~/.gitconfig`

Add the following to your `~/.gitconfig`:

```ini
[include]
    path = ~/Projects/gitconfig/gitconfig
```

Alternatively, import only the modules you need:

```ini
[include]
    path = ~/Projects/gitconfig/git/defaults.inc     # Modern Git defaults
    path = ~/Projects/gitconfig/git/stacked.inc      # Stacked PR/branch workflow
    path = ~/Projects/gitconfig/git/difftastic.inc   # Difftastic diff/log aliases
    path = ~/Projects/gitconfig/git/hooks.inc        # Jira branch-prefix commit hook
```

---

## Modules

### 1. Modern Defaults (`git/defaults.inc`)

Enables modern, safe, and productive Git settings:
- **Diff & Merge**: `histogram` diff algorithm, `colorMoved = plain`, `mnemonicPrefix = true`, `zdiff3` conflict style.
- **Rebase & Pull**: `pull.rebase = true`, `rebase.autoSquash = true`, `rebase.autoStash = true`, `rebase.updateRefs = true`.
- **Hygiene & Safety**: `rerere.enabled = true`, `commit.verbose = true`, `help.autocorrect = prompt`, `push.autoSetupRemote = true`, `fetch.prune = true`.

### 2. Stacked Git Workflow (`git/stacked.inc`)

Streamlines stacked branch development and pull requests.

| Command | Description |
| :--- | :--- |
| `git stack [branch]` | Displays all commits and branch points in the stack between the origin default branch and `HEAD`. |
| `git push-stack [branch]` | Pushes all branches in the stack in topological order (bottom-up) with `--force-with-lease`. |
| `git rebase-stack` | Interactively rebases the entire stack against the origin default branch merge-base. |
| `git absorb-stack` | Automatically absorbs staged modifications into the correct commits in the current stack using `git-absorb`. |
| `git pr-stack [branch]` | Automatically creates or updates GitHub PRs for every branch in the stack using `gh`, chaining their base branches appropriately. |

**Prerequisites**:
```bash
brew install git-absorb git-interactive-rebase-tool gh
```

### 3. Difftastic Integration (`git/difftastic.inc`)

Aliases for syntax-aware structural diffs using [Difftastic](https://difftastic.wilfred.me.uk/):
- `git dlog` / `git dl`: Log with difftastic output.
- `git dshow` / `git ds`: Show commit with difftastic.
- `git ddiff` / `git dft`: Diff with difftastic.

**Prerequisites**:
```bash
brew install difftastic
```

### 4. Jira Ticket Prefix Hook (`git/hooks.inc`)

Uses Git 2.54+ config-based hooks (`[hook]`). Inspects the active branch name for any Jira ticket pattern (`[A-Z]{2,}-[0-9]+`, e.g. `PROJ-1234-my-feature`) and automatically prepends `PROJ-1234: ` to the commit message.

Does not modify merge, amend, fixup, or squash commits.
