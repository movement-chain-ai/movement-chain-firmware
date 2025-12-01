# Setup Instructions for Movement Chain Firmware

This document provides step-by-step instructions to complete the Git hooks setup.

## What Has Been Created

The following files and directories have been set up for you:

### Core Configuration Files
- `package.json` - Node.js dependencies and scripts
- `commitlint.config.js` - Commit message validation rules
- `.clang-format` - C++ code formatting rules (Google style)
- `platformio.ini` - PlatformIO configuration for ESP32-S3
- `.gitignore` - Ignore patterns for build artifacts, node_modules, etc.

### Git Hooks (in `.husky/` directory)
- `commit-msg` - Validates commit message format
- `pre-commit` - Formats code and checks for issues
- `pre-push` - Builds firmware and runs tests

### GitHub Actions
- `.github/workflows/pr-validation.yml` - Automated PR validation workflow

### Documentation
- `README.md` - Project overview and quick start
- `HOOKS_SETUP.md` - Detailed Git hooks documentation
- `SETUP_INSTRUCTIONS.md` - This file

### Source Structure
- `src/main.cpp` - Sample main file
- `lib/` - Custom libraries directory
- `test/` - Unit tests directory

## Next Steps

### 1. Install Node.js Dependencies

Run this command in the firmware repository root:

```bash
cd /Users/maxwsy/Desktop/workspace/movement-chain-firmware
npm install
```

This will:
- Install Husky, commitlint, and other dev dependencies
- Automatically initialize Git hooks via the `prepare` script

### 2. Verify Hook Installation

Check that hooks are properly installed:

```bash
ls -la .husky/
```

You should see executable hooks:
- `commit-msg`
- `pre-commit`
- `pre-push`

### 3. Install Optional Tools

#### Install clang-format (Recommended for code formatting)

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

#### Install PlatformIO (Required for pre-push validation)

```bash
pip install platformio
```

Or install via the PlatformIO IDE extension for VS Code.

### 4. Test the Setup

#### Test Commit Message Validation

Try making a commit with an invalid message:

```bash
git add .
git commit -m "invalid commit message"
```

This should fail with a commitlint error.

Now try a valid commit:

```bash
git commit -m "chore: initial setup"
```

This should succeed.

#### Test Pre-Commit Hook

1. Create a test file with debug statements:
```bash
echo 'void test() { Serial.println("test"); }' > src/test.cpp
git add src/test.cpp
git commit -m "test: add test file"
```

The pre-commit hook should warn about debug print statements.

#### Test Pre-Push Hook

Make sure PlatformIO is installed, then:

```bash
git push origin main
```

The hook will build the firmware before pushing.

### 5. Configure Git Branch (Optional)

If you want to use `main` as the default branch instead of `master`:

```bash
git branch -m master main
```

### 6. Create Remote Repository

If you haven't already, create a GitHub repository and link it:

```bash
git remote add origin https://github.com/yourusername/movement-chain-firmware.git
git push -u origin main
```

### 7. Enable GitHub Actions

Once you push to GitHub:
1. Go to your repository settings
2. Navigate to Actions
3. Enable GitHub Actions if not already enabled
4. The PR validation workflow will run automatically on pull requests

## Verification Checklist

- [ ] Node.js dependencies installed (`npm install`)
- [ ] Git hooks are executable
- [ ] Commit message validation works
- [ ] Pre-commit hook runs (warnings about debug statements)
- [ ] Pre-push hook builds firmware (requires PlatformIO)
- [ ] clang-format installed (optional)
- [ ] PlatformIO installed
- [ ] Remote repository created
- [ ] GitHub Actions enabled

## Troubleshooting

### Hooks Not Running

If hooks don't execute:

```bash
npx husky install
chmod +x .husky/commit-msg .husky/pre-commit .husky/pre-push
```

### commitlint Not Found

```bash
npm install
npx husky install
```

### PlatformIO Build Fails

Make sure PlatformIO is installed:
```bash
pip install platformio
pio --version
```

Or skip the hook temporarily:
```bash
git push --no-verify
```

### Permission Denied on Hooks

Make hooks executable:
```bash
chmod +x .husky/commit-msg .husky/pre-commit .husky/pre-push
```

## Additional Resources

- [HOOKS_SETUP.md](HOOKS_SETUP.md) - Detailed Git hooks documentation
- [Conventional Commits](https://www.conventionalcommits.org/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Husky Documentation](https://typicode.github.io/husky/)

## Summary

Your firmware repository is now configured with:
- Automated commit message validation
- Code formatting on commit
- Build validation before push
- GitHub Actions for PR validation

Run `npm install` to complete the setup, then start developing!

---

**Created:** December 2025
