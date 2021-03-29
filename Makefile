upload:
	arduino-cli upload -p /dev/ttyACM0 --fqbn Seeeduino:samd:seeed_wio_terminal thereminvox

build:
	arduino-cli compile --fqbn Seeeduino:samd:seeed_wio_terminal thereminvox

deps:
	arduino-cli lib install --git-url https://github.com/Seeed-Studio/Seeed_Arduino_FreeRTOS
	arduino-cli lib install --git-url https://github.com/lovyan03/LovyanGFX
	arduino-cli lib install --git-url https://github.com/Seeed-Studio/Seeed_Arduino_LIS3DHTR/
