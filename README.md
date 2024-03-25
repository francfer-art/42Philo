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
- [Mandatory Part](#Mandatory-Part)
- [Bonus Part](#Bonus-Part)
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

## Mandatory Part

```

The specific rules for the mandatory part are:

· Each philosopher should be a thread.

· There is one fork between each pair of philosophers. Therefore, if there are several
  philosophers, each philosopher has a fork on their left side and a fork on their right
  side. 
  If there is only one philosopher, there should be only one fork on the table.

· To prevent philosophers from duplicating forks, you should protect the forks state
  with a mutex for each of them.

```

## Bonus Part

```
The program of the bonus part takes the same arguments as the mandatory program.
It has to comply with the requirements of the Global rules chapter.

The specific rules for the bonus part are:

· All the forks are put in the middle of the table.

· They have no states in memory but the number of available forks is represented by
  a semaphore.

· Each philosopher should be a process. But the main process should not be a
  philosopher.

```

## Usage

```

git clone https://github.com/francfer-art/42Philo.git
cd 42Philo/philo or cd 42Philo/philo_bonus
make
./philo 5 800 200 200 [5]
./philo_bonnus 5 800 200 200 [5]

```

## Contributing

Contributions are welcome! If you have improvements or additional features to suggest, please open an issue or submit a pull request. Follow the Contribution Guidelines for more details.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
