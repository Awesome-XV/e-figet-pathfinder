# e-figet-pathfinder
This is a project that allows you to play around with switches and LED's. It's a reaction game ... for now, I am planning to make a settings/page button that allows you to play different game modes and stuff. But now it's geared toward an *F1* style gameplay where the LED's close in on the center light and then they all go blank and it measures the time for you to let go of the "clutch" and hit the "accelerator". Maybe different racing types later??
I made this project as an intro into PCB's, circuits and soldering because it's my first physical project that I have done. I wanted to get into the hardware project and there was a nice guide, but no soldering guide so I get to do that on my own. So this is a bit later, and I added a battery compartment to it, it's now a mobile device and it doesn't have to be plugged in. I also am now planning to add a GT practice shifter to the code where you can practice shifting GT style.

# Some Pics
<img width="2362" height="1377" alt="eFidget" src="https://github.com/user-attachments/assets/ca312ac3-5c5e-4eec-aa61-a1695c8b89b5" />
<img width="1260" height="774" alt="image" src="https://github.com/user-attachments/assets/8ddf0273-d7d5-45c7-aaa7-efaa1ce420b3" />
<img width="1698" height="781" alt="image" src="https://github.com/user-attachments/assets/4367740a-5229-4546-ac3b-bb26a926bc82" />
<img width="1494" height="686" alt="image" src="https://github.com/user-attachments/assets/418a99df-743d-4dba-8887-59bdb1c45122" />



# BOM Table
| Name | Purpose | Quantity | Total Cost (USD) | Distributor | Link |
|------|---------|:--------:|-----------------:|-------------|------|
| XIAO RP2040 | MC, controls everything | 1 | $4.68 | Digikey | [Buy](https://www.digikey.com/en/products/detail/seeed-technology-co-ltd/102010428/14672129) |
| LED RED 5MM | Lights up | 7 | $1.05 | Digikey | [Buy](https://www.digikey.com/en/products/detail/w%C3%BCrth-elektronik/151051RS11000/4490012) |
| Through Hole Resistors | For the LEDs | 10 | $0.22 | Digikey | [Buy](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF18JT110R/1741570) |
| MX SWITCH 12V | Switch to trigger actions | 4 | $5.00 | Digikey | [Buy](https://www.digikey.com/en/products/detail/cherry-americas-llc/MX1A-C1NW/280855) |
| BLACK KEYCAPS | Keycaps for the MX switches | 1 | $5.95 | Digikey | [Buy](https://www.digikey.com/en/products/detail/adafruit-industries-llc/4997/14552180) |
| Battery Compartment | To hold the batteries | 1 | $1.77 | Digikey | [Buy](https://www.digikey.com/en/products/detail/keystone-electronics/2465/303814) |
| Connectors | To provide a place for the red and black wires to hook onto | 10 | $0.29 | Digikey | [Buy](https://www.digikey.com/en/products/detail/adam-tech/PH1-01-UA/9830231) |
| Diode | To prevent reverse current flow | 1 | $0.18 | Digikey | [Buy](https://www.digikey.com/en/products/detail/smc-diode-solutions/1N5817/21705460) |
| PCB | For connection | 1 | $2.00 | JLCPCB | N/A |
| Shipping | Move these parts | 1 | $10.29 | JLCPCB, Digikey | N/A |
| Tax | I have to pay | 1 | $2.22 | Digikey | N/A |
| Tariffs | Quantity means 5 products I have tax on | 5 | $0.79 | Digikey | N/A |
| **Total** | | | *$34.44* | | |

