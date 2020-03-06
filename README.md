# r_giskard
Small project for experiments with unconditioned and conditioned reflexes

## Common Terms

**A reflex**, or reflex action, is an involuntary and nearly instantaneous movement in response to a stimulus. A reflex is made possible by neural pathways called reflex arcs which can act on an impulse before that impulse reaches the brain. The reflex is then an automatic response to a stimulus that does not receive or need conscious thought.
[Source: Reflex - Wikipedia](https://en.wikipedia.org/wiki/Reflex)

**Classical conditioning** occurs when a conditioned stimulus (CS) is paired with an unconditioned stimulus (US). Usually, the conditioned stimulus is a neutral stimulus (e.g., the sound of a tuning fork), the unconditioned stimulus is biologically potent (e.g., the taste of food) and the unconditioned response (UR) to the unconditioned stimulus is an unlearned reflex response (e.g., salivation). After pairing is repeated the organism exhibits a conditioned response (CR) to the conditioned stimulus when the conditioned stimulus is presented alone. (A conditioned response may occur after only one pairing.) Thus, unlike the UR, the CR is acquired through experience, and it is also less permanent than the UR.
[Source: Classical conditioning - Wikipedia](https://en.wikipedia.org/wiki/Classical_conditioning)

## Project-specific Terms

Reflex here - is a hardly connected with used hardware program module containing algoritm, executed with an interruption.

* Reflex could be unconditioned (UR) - simple hardcoded interruption.
* Reflex could be conditioned (CR):
    * before an UR some unhandled interruption is happening more then once
    * after N times of paires UR_n+CR_m is registered in a system. Thats means than given UR is becoming the handler of given CR.

## Structure

Interruptions types:

<img src="https://www.lucidchart.com/publicSegments/view/f6ef18fb-de43-4d13-a4d6-0691f0f8afb9/image.png" width="250">

Core scturcture draft:

<img src="https://www.lucidchart.com/publicSegments/view/ece67a32-13b0-4cd7-8846-a047248b2351/image.png" width="500">
