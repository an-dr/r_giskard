# Emotional Core

The aim of this library is to implement emotional model that could be used by other applications to implement a behavior modifications based on changing of input data. E.g. a robot can change it's behavior based on data from sensors.

## Structure

<img src="docs/pics/EmotionalCore_ops_simple.png" width="550">

Emotional core consists of three main parts:

- Input Data Descriptors - describes data from sensors and how it should affect the core
- Emotional States Descriptors - named states of the core described by specific values of core parameters.
- Core State - contains core parameters, value of sensors and pointer to relevant to parameters Emotional  States Descriptors

Detailed structure:

<img src="docs/pics/EmotionalCore_ops_detailed.png" width="550">

## Example of data

Example of core parameters:

```json
[   "cortisol",
    "dopamine",
    "adrenaline",
    "serotonin" ]
```

Example of a core's emotional state:

```json
{
    "name": happiness,
    "conditions": [
            {
                "param":  "cortisol",
                "op":     LESS_THAN,
                "value":  10
            },
            {
                "param":  "serotonin",
                "op":     GREATER_THAN,
                "value":  100
            }
        ]
}
```

Example of input data descriptor:

```json
{
    "sensor_name": "temperature sensor",
    "val_min": 0,
    "val_max": 255,
    "weights": [
        {
            "core_param_name": "serotonin",
            "weight": 0.5
        },
        {
            "core_param_name": "cortisol",
            "weight": -0.5
        }
    ]
}
```

Input data example:

```json
{
    "sensor_name": "temperature sensor",
    "value": 120
}
```

## Writing new data

When you write the data, the core does the following:

- updates saved sensor value
- updates core parameter: param += (new_sens_val - old_sens_val) * weight
- updates the current core state based on updated parameters