%For this stage, I worked to add all the conditionals that could occur
%based on playerinitialhands, then dealerinitialhands, and then final hands
%Also had to make sure when to stop a loop and how to as initially break
%resulted in dealer hand being dealt despite player going bust. the user
%capital was also manipulated based on each condition

%as I finished with the condtions, I realised that i also have make the
%aces be equal to 11 or 1 depending on hand value. Hence i also added the
%condtions for aces inside the hit loops for both players and dealers

%Actual Blackjack game
fprintf ("\n"); % to make it a bit clearer from introductory inputs

%Initialising Deck
cards={'Ace','2','3','4','5','6','7','8','9','10','Jack','Queen','King'};
suit={'Hearts','Spades','Diamonds','Clubs'};
values=[11,2,3,4,5,6,7,8,9,10,10,10,10];

% creates and print the player hand
shuffle_card=randi([1 13],2);
shuffle_suit=randi([1 4],2);
total=values(shuffle_card(1))+values(shuffle_card(2));
fprintf("your cards are (%s of %s) and (%s of %s)\n",cards{shuffle_card(1)},suit{shuffle_suit(1)},cards{shuffle_card(2)},suit{shuffle_suit(2)});
fprintf("your total value is %d\n",total);

% Creates dealer hand and prints one card, whilst storing the other value
% and printing out "hidden"
shuffle_card_dealer=randi([1 13],2);
shuffle_suit_dealer=randi([1 4],2);
fprintf("\ndealer cards are (%s of %s) and (hidden)\n",cards{shuffle_card_dealer(1)},suit{shuffle_suit_dealer(1)})
fprintf ("Current dealer total is %d \n",values(shuffle_card_dealer(1)))


%hit and stand action for player
while true % keep looping until valid input is entered
    hit = input("\nHit(H), Stay(S): ", 's');
    hit =lower(hit); %makes the above inputs lowercase for easier conditionals

    if hit == 'h' || hit == 's' % check for valid input and if valid input found
        break
    else
        fprintf("Invalid input, please enter 'h' or 's'.\n") %prints if invalid input
    end
end


while hit == 'h' %this loop keeps going as long as the user hits, or other condtions such as bust or blackjack(which are implemented inside)
    shuffle_card1=randi([1 13],1); %picks a new value for next card
    shuffle_suit1=randi([1 4],1); %picks a new suit for next card


    % handle the value of Aces by checking the total value of the previous hand
    % is more than 10 and shifting ace value to equal 1 if so
    if (shuffle_card1 == 1) && total  > 10
        values(shuffle_card1) = 1;
    end

    total=values(shuffle_card1)+total; %adds the value of new card to previous total

    fprintf("\nyour next card is (%s of %s)\n",cards{shuffle_card1},suit{shuffle_suit1}) %prints name of next card
    fprintf("your total value is %d\n",total) %prints new total value of hand
    if total>21 %output for a bust
        fprintf("\nYou BUSTED, its ok dont give up \n")
        user_capital= user_capital - bet_initial ;
        fprintf("Your capital is now: %d ", user_capital)
        return
    elseif total==21 %output for a blackjack
        fprintf("\nBLACKJACK, eh every dog has it's day \n")
        user_capital= user_capital + (bet_initial *1.5); % adds bet * 1.5 as blackjack pays 3/2
        fprintf("\nYour capital is now: %d\n ", user_capital)
        return
    end

    hit=input("\nHit(H), Stay(S): ", 's'); % repeats input

    if hit=='s' %breaking the loop and ending players turn once player inputs stand
        break
    end
end



%Revealing dealer hand and total value
dealer_total=values(shuffle_card_dealer(1))+ values(shuffle_card_dealer(2)); %adds card values together
fprintf('\ndealer cards are (%s of %s) and (%s of %s)\n',cards{shuffle_card_dealer(1)},suit{shuffle_suit_dealer(1)},cards{shuffle_card_dealer(2)},suit{shuffle_suit_dealer(2)})
fprintf('dealer total value is %d\n',dealer_total)
if dealer_total==21 %dealer initial blackjack
    fprintf("BLACKJACK BABY")
    return
end
%Dealer takes action depending on hand value, must hit if hand is less than
%17, and 22 is a standoff
while dealer_total<17 %must keep hitting
    dealer_shuffle_card1=randi([1 13],1);
    dealer_shuffle_suit1=randi([1 4],1);
    dealer_total=values(dealer_shuffle_card1)+dealer_total; %adds new card value to previous hand total

    % handle the value of Aces
    if dealer_shuffle_card1 == 1 && dealer_total > 10
        values(shuffle_card1) = 1;
    end

    % Checking for all cases after dealer is finished dealing his hand
    fprintf("\nDealer's next card is (%s of %s)\n",cards{dealer_shuffle_card1},suit{dealer_shuffle_suit1})
    fprintf("Dealer's total value is %d\n",dealer_total)
    if dealer_total>22 %dealer bust
        fprintf("\noops I BUSTED, sorry freudian slip.")
        user_capital= user_capital + (bet_initial); %bet is doubled and added to capital if dealer busts
        fprintf("\nYour capital is now: %d\n ", user_capital)

        break
    elseif dealer_total==22 %standoff rule
        fprintf("\nSTANDOFF, just like those old cowboy movies.")
        fprintf("\nYour capital is now: %d\n ", user_capital) %capital doesnt change, as bet is refunded
        break
    elseif dealer_total==21 %dealer blackjack
        fprintf("\nWooooo baby it's a BLACKJACK!!!.")
        user_capital= user_capital - (bet_initial); %dealer win, hence bet deducted
        fprintf("\nYour capital is now: %d\n ", user_capital)
        break
    elseif dealer_total>total %if dealer hand higher than player
        fprintf("\nI WIN, are u rlly suprised???")
        user_capital= user_capital - (bet_initial);
        fprintf("\nYour capital is now: %d\n ", user_capital)
    elseif dealer_total<total %if dealer hand lower than player
        fprintf("\nthats YOUR WIN, dont get too smug")
        user_capital= user_capital + (bet_initial);
        fprintf("\nYour capital is now: %d\n ", user_capital)

    elseif dealer_total==(total) %equal hand to player
        fprintf("\nSTANDOFF, just like those old cowboy movies.")
        fprintf("\nYour capital is now: %d\n ", user_capital) %capital doesnt change, as bet is refunded
        break

    end
end
