# LED_necktie


## Components

### Amount of bus-pins
SPI requires 3 pins for SCK, MISO and MOSI. The middle bus is reserved to GND. Since the design should be mirrored, the total amount of pins on the bus is (3 + x)*2 + 1, with x being the amount of pins dedicated to (multiplexing) chip select.

I.e. if 4 pins are dedicated to CHPSLCK (meaning 2^4-1=15 slaves can be selected (since 0 from the demux must be no-connect to allow selecting no slaves (MEN CHIP 0 er alltid MASTER!))) then 15 pins are needed. This exists.

Alternatively: One could use a non-doubled bus and connect to two spi-ports, one being flipped. Then a build flag could define which definition is used.

