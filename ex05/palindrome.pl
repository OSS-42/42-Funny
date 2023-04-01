#!/usr/bin/perl

use strict;
use warnings;

print "Enter a string: ";
my $input = <STDIN>;
chomp($input);

my $reversed = reverse($input);

if (lc($input) eq lc($reversed)) {
	print "The string is a palindrome!\n";
} else {
	print "The string is not a palindrome.\n";
}
