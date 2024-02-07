% I added the offer_leverage function inside loop
% afterwards, i added a intial betting input/output code which used the
% newly updated capital after leverage function had been applied
%I initially planned to make the betting a seperate function, however as my
%full game was going to be seperate function which would require the
%betting variables and that the betting code was short, i decided to leave
%it as it is in the main loop
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


        %intitalize the user's capital
        user_capital = input("How much money would you like to play with: $");

        % Making the dealer respond based on the user's capital
        if user_capital < 100
            disp("ALL RIGHT, LET'S BEGIN MY CASH-STRAPPED FRIEND!");
        elseif user_capital >= 100 && user_capital < 1000
            disp("ALL RIGHT LET US BEGIN!!")
        elseif  user_capital >= 1000
            disp("Are you single by any chance, he he he I am simply jesting. ALL RIGHT LET US BEGIN!!!")
        end

        %Offering leverage on initial capital and changing capital value on that by
        %calling on offer_leverage function
        [user_capital, leverage_value] = offer_leverage(user_capital);

        % Initialising bet and making dealer respond based on bet size in
        % proportion to capital
        valid_bet = false;
        while ~valid_bet

            bet_initial = input("Place your bet: $");

            if bet_initial > user_capital || bet_initial <= 0
                disp("Sorry, your bet cannot be higher than your current capital or less than 0, please stay within your limits\n");
                image2=imread("broke.PNG");
                imshow(image2) %image display if the bet higher than user capital
            elseif bet_initial >= (user_capital/2)
                disp("Guess someone never learned risk management, he he he");
                valid_bet = true;
            elseif  bet_initial <= (user_capital/20)
                disp("Guess someone's here to make chump change returns, may I suggest an index fund instead")
                valid_bet = true;
            else
                disp("a basic bet for a basic ... man")
                valid_bet = true;
            end
        end


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

