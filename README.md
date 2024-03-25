<a href="https://github.com/francfer-art/42Philo">
  <img src ="https://github.com/15Galan/42_project-readmes/blob/master/banners/cursus/projects/philosophers-dark.png?raw=true")>
</a>

<p align="center">
  <a href="https://github.com/francfer-art/42Philo">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/philosophersm.png?raw=true" alt="Philo Logo">
  </a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Score-Ongoing-brightgreen" alt="Philo Score">
</p>

## Table of Contents

- [Introduction](#introduction)
- [Global Rules](#Global-Rules)
- [Usage](#Usage)
- [Bonus](#bonus)
- [Contributing](#contributing)
- [License](#license)

## Introduction

In this simulation, philosophers sit around a round table with a large bowl of spaghetti in the middle. They alternately eat, think, or sleep. Each philosopher must eat to avoid starving, but they must also balance their time between eating, thinking, and sleeping.

## Global Rules

```

You have to write a program for the mandatory part and another one for the bonus part (if you decide
to do the bonus part). They both have to comply with the following rules:

· Global variables are forbidden!

· Your(s) program(s) should take the following arguments: number_of_philosophers time_to_die time_to_eat
  time_to_sleep [number_of_times_each_philosopher_must_eat]

  · number_of_philosophers: The number of philosophers and also the number of forks.
  · time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since
    the beginning of their last meal or the beginning of the simulation, they die.
  · time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they
    will need to hold two forks.
  · time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
  · number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least
    number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the
    simulation stops when a philosopher dies.

· Each philosopher has a number ranging from 1 to number_of_philosophers.

· Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher
  number N sits between philosopher number N - 1 and philosopher number N + 1.

· Any state change of a philosopher must be formatted as follows:

  · timestamp_in_ms X has taken a fork
  · timestamp_in_ms X is eating
  · timestamp_in_ms X is sleeping
  · timestamp_in_ms X is thinking
  · timestamp_in_ms X died

Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.

· A displayed state message should not be mixed up with another message.

· A message announcing a philosopher died should be displayed no more than 10ms after the actual
  death of the philosopher.

· Again, philosophers should avoid dying!

```

## Contributing

Contributions are welcome! If you have improvements or additional features to suggest, please open an issue or submit a pull request. Follow the Contribution Guidelines for more details.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
