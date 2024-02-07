%First parts I wrote, The rules were straighforward to print and also gave
%me a guidelines for what I am trying to accomplish with the main black
%jack game. So i wrote the overarching loop which would start based on user
%input of yes and no and then I could start writing my parts seperately and
%integrating it in within the loop.
clc;
clear all

%printing the rules and also a guideline for myself as to what I was trying
%to achieve with my code
fprintf("Welcome to Blackack plus, which is blackjack with our house rules \n");
fprintf("Blackjack pays with 2:1 odds \n");
fprintf("Blackjack on intial hand pays with 3:2 odds \n");
fprintf("Dealer hits if under 17 and stands if equal to or above 17 \n");
fprintf("Standoff when dealer hand is equal to 22 \n \n");

%start of main loop
valid_input = false;
while ~valid_input

    %Get User Input if to play or not, and outputting a correspoding output
    player_choice = input("Would you like to play, press either Y/N: ", 's');

    if strcmpi(player_choice, 'y')% compares user input to 'y' or 'Y'
        disp("Good choice, remember you can win upto 2000% of your money when gambling but can only lose 100% of it, so do the math! ");



        %end the program
        valid_input = true;
        % program output if  user inputs "N"/"n" or an invalid input
    elseif strcmpi(player_choice, 'n')
        disp("There are winners and then there are quitters, guess your the latter.");
        valid_input = true;
    else
        fprintf("THATS AN INVALID INPUT!!!!, \n sorry I got a little heated, lets try again")
    end
end

