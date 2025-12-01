# Git Hooks Setup Guide

This repository uses **Husky** for Git hooks and **commitlint** for commit message validation to ensure code quality and consistency.

## Prerequisites

- **Node.js** (v18 or higher)
- **npm** (v9 or higher)
- **PlatformIO** (optional, for pre-push validation)
- **clang-format** (optional, for code formatting)

## Installation

### 1. Install Dependencies

Run the following command in the repository root:

```bash
npm install
```

This will:
- Install Husky, commitlint, and other dev dependencies
- Initialize Husky hooks automatically via the `prepare` script

### 2. Verify Hook Installation

Check that hooks are installed:

```bash
ls -la .husky/
```

You should see:
- `commit-msg` - Validates commit message format
- `pre-commit` - Runs code formatting and checks
- `pre-push` - Builds firmware and runs tests

## Git Hooks Overview

### Commit Message Hook (`commit-msg`)

**Purpose:** Ensures all commit messages follow the Conventional Commits standard.

**Format:**
```
<type>: <subject>

[optional body]

[optional footer]
```

**Allowed types:**
- `feat` - New feature
- `fix` - Bug fix
- `perf` - Performance improvement
- `refactor` - Code refactoring
- `test` - Adding or updating tests
- `docs` - Documentation changes
- `chore` - Maintenance tasks
- `ci` - CI/CD changes
- `build` - Build system changes
- `revert` - Reverting changes

**Examples:**
```bash
git commit -m "feat: add BLE GATT server implementation"
git commit -m "fix: resolve memory leak in WiFi manager"
git commit -m "perf: optimize sensor polling frequency"
git commit -m "docs: update platformio.ini configuration guide"
```

**Invalid examples:**
```bash
git commit -m "Added new feature"  # ❌ Missing type
git commit -m "FEAT: add feature"  # ❌ Type must be lowercase
git commit -m "feat: Add feature." # ❌ Subject should not end with period
```

### Pre-Commit Hook (`pre-commit`)

**Purpose:** Performs code quality checks before each commit.

**Actions:**
1. **Debug Statement Check** - Warns about `Serial.print`, `printf`, or `cout` statements
2. **TODO/FIXME Detection** - Lists TODO and FIXME comments (non-blocking)
3. **Code Formatting** - Formats C++ files using clang-format (Google style)

**Non-blocking warnings** are displayed but won't prevent commits.

**To skip (not recommended):**
```bash
git commit -m "feat: message" --no-verify
```

### Pre-Push Hook (`pre-push`)

**Purpose:** Validates firmware build before pushing to remote.

**Actions:**
1. **Build Firmware** - Compiles firmware for ESP32-S3
2. **Size Check** - Warns if firmware exceeds 1MB
3. **Run Tests** - Executes PlatformIO tests (if configured)

**Requirements:**
- PlatformIO must be installed (`pip install platformio`)
- `platformio.ini` must have an `esp32-s3` environment

**To skip (use with caution):**
```bash
git push --no-verify
```

## Optional Tools

### Install clang-format (Recommended)

**macOS:**
```bash
brew install clang-format
```

**Ubuntu/Debian:**
```bash
sudo apt install clang-format
```

**Windows:**
```powershell
choco install llvm
```

### Install PlatformIO (Required for pre-push)

```bash
pip install platformio
```

## Troubleshooting

### Issue: Hooks not executing

**Solution:**
```bash
npm run prepare
chmod +x .husky/commit-msg .husky/pre-commit .husky/pre-push
```

### Issue: commitlint fails with "command not found"

**Solution:**
```bash
npm install
npx husky install
```

### Issue: Pre-push fails with "PlatformIO not found"

**Solution:**
Install PlatformIO or skip the hook temporarily:
```bash
git push --no-verify
```

### Issue: clang-format not found

**Solution:**
This is optional. Install clang-format or ignore the warning.

## CI/CD Integration

This repository includes GitHub Actions workflows that:
- Build firmware on every PR
- Check binary size
- Run tests
- Upload firmware artifacts

See `.github/workflows/pr-validation.yml` for details.

## Customization

### Modify Commit Types

Edit `commitlint.config.js`:
```javascript
'type-enum': [
  2,
  'always',
  ['feat', 'fix', 'custom-type'],  // Add your types here
],
```

### Adjust Pre-Commit Checks

Edit `.husky/pre-commit` to add or remove checks.

### Change Firmware Size Limit

Edit `.husky/pre-push` and modify:
```bash
if [ $SIZE -gt 1048576 ]; then  # Change 1048576 (1MB) to your limit
```

## Best Practices

1. **Always write descriptive commit messages** following the Conventional Commits format
2. **Run `npm install`** after cloning the repository
3. **Don't skip hooks** unless absolutely necessary
4. **Keep commits atomic** - one logical change per commit
5. **Test locally** before pushing to ensure pre-push validation passes

## Resources

- [Conventional Commits](https://www.conventionalcommits.org/)
- [Husky Documentation](https://typicode.github.io/husky/)
- [commitlint](https://commitlint.js.org/)
- [PlatformIO](https://platformio.org/)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html)

## Support

For issues or questions:
1. Check this documentation
2. Review hook scripts in `.husky/`
3. Check GitHub Actions logs for CI failures
4. Contact the maintainer

---

**Last Updated:** December 2025
