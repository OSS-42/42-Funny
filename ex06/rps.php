<?php

function getUserInput()
{
	echo "Choose rock, paper, or scissors: ";
	$input = trim(fgets(STDIN));
	return strtolower($input);
}

function getComputerChoice()
{
	$choices = ['rock', 'paper', 'scissors'];
	return $choices[array_rand($choices)];
}

function determineWinner($userChoice, $computerChoice)
{
	if ($userChoice === $computerChoice) {
		return "It's a draw! The computer chose ";
	}

	switch ($userChoice) {
		case 'rock':
			return ($computerChoice === 'scissors') ? "Congratulations! You won! The computer chose " : "Sorry, you lost. The computer chose ";
		case 'paper':
			return ($computerChoice === 'rock') ? "Congratulations! You won! The computer chose " : "Sorry, you lost. The computer chose ";
		case 'scissors':
			return ($computerChoice === 'paper') ? "Congratulations! You won! The computer chose " : "Sorry, you lost. The computer chose ";
		default:
			return "Invalid input. Please choose rock, paper, or scissors.";
	}
}

$userChoice = getUserInput();
$computerChoice = getComputerChoice();

$result = determineWinner($userChoice, $computerChoice);
echo $result;
echo $computerChoice . PHP_EOL;

?>