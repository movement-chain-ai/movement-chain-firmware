# Movement Chain Firmware

ESP32-S3 firmware for the Movement Chain project.

## Hardware

- **Board:** ESP32-S3 DevKitC-1
- **Framework:** Arduino
- **Platform:** PlatformIO

## Quick Start

### Prerequisites

- [PlatformIO](https://platformio.org/) installed
- Node.js v18+ (for Git hooks)

### Installation

1. Clone the repository:
```bash
git clone <repository-url>
cd movement-chain-firmware
```

2. Install dependencies:
```bash
npm install
```

3. Build the firmware:
```bash
pio run
```

4. Upload to device:
```bash
pio run --target upload
```

5. Monitor serial output:
```bash
pio device monitor
```

## Development

### Git Hooks

This project uses Husky for Git hooks. See [HOOKS_SETUP.md](HOOKS_SETUP.md) for details.

### Commit Message Format

Follow Conventional Commits:
```
<type>: <subject>
```

Types: `feat`, `fix`, `perf`, `refactor`, `test`, `docs`, `chore`, `ci`

Example:
```bash
git commit -m "feat: add BLE GATT server"
```

### Code Formatting

Code is automatically formatted using clang-format (Google style) on commit.

## Project Structure

```
movement-chain-firmware/
├── src/                 # Source files
├── lib/                 # Custom libraries
├── test/                # Unit tests
├── platformio.ini       # PlatformIO configuration
├── .husky/              # Git hooks
└── package.json         # Node.js dependencies
```

## Testing

Run tests:
```bash
pio test
```

## CI/CD

GitHub Actions automatically:
- Builds firmware on every PR
- Checks binary size
- Runs tests
- Uploads artifacts

## License

[Add your license here]

## Contributing

1. Create a feature branch
2. Make changes following the commit convention
3. Push and create a PR
4. Wait for CI validation
