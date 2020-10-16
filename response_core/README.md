# Response core

Under early development

## Project-specific Terms

Reflex here - is a hardly connected with used hardware program module containing algorithm, executed with an interruption.

* Reflex could be unconditioned (UR) - simple hardcoded interruption.
* Reflex could be conditioned (CR):
    * before an UR some unhandled interruption is happening more then once
    * after N times of pairs UR_n+CR_m is registered in a system. That's means than given UR is becoming the handler of given CR.

## Structure

Interruptions types:

<img src="https://www.lucidchart.com/publicSegments/view/f6ef18fb-de43-4d13-a4d6-0691f0f8afb9/image.png" width="250">

Core structure draft:

<img src="https://www.lucidchart.com/publicSegments/view/ece67a32-13b0-4cd7-8846-a047248b2351/image.png" width="500">
