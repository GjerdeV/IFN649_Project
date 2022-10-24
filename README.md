# IFN649_Project
This is a project in unit IFN649 at QUT in Brisbane done by Martin Gjerde.

The distributed alarm clock have a seperated alarmbuzzer and button to turn it off. This is to force
the user to get up from their bed in the morning.

Temperature is measured by the bed to indicate to the user whether to turn up or down the heating/cooling
to improve sleeping quality.
This can also be advanced to control a heating and/or cooling element to automate this process.

HTML code is added to give an external interface through AWS websockets, in case the user is not
at home when alarm goes off, so it can be turned off remotely. The website also gives the user
the possibility to monitor the room's temperature.

The set temperature is only set for testing purposes and should be changed if used for real life scenario.
