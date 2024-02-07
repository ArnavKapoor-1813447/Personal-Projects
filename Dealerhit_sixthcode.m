% for this part of my project, i worked to add code which would reveal the
% dealers full hand and then create a simple hit loop which would add cards
% to dealer hand until the total was 17 or above.


%Actual blackjack game
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

    total=values(shuffle_card1)+total; %adds the value of new card to previous total

    fprintf("\nyour next card is (%s of %s)\n",cards{shuffle_card1},suit{shuffle_suit1}) %prints name of next card
    fprintf("your total value is %d\n",total) %prints new total value of hand


    hit=input("\nHit(H), Stay(S): ", 's');

    if hit=='s' %breaking the loop and ending players turn once player inputs stand
        break
    end
end


%Revealing dealer hand and total value
dealer_total=values(shuffle_card_dealer(1))+ values(shuffle_card_dealer(2)); %adds card values together
fprintf('\ndealer cards are (%s of %s) and (%s of %s)\n',cards{shuffle_card_dealer(1)},suit{shuffle_suit_dealer(1)},cards{shuffle_card_dealer(2)},suit{shuffle_suit_dealer(2)})
fprintf('dealer total value is %d\n',dealer_total)
if dealer_total==21
    fprintf("BLACKJACK BABY")
    return
end
%Dealer takes action depending on hand value, must hit if hand is less than
%17, and 22 is a standoff
while dealer_total<17
    dealer_shuffle_card1=randi([1 13],1);
    dealer_shuffle_suit1=randi([1 4],1);
    dealer_total=values(dealer_shuffle_card1)+dealer_total; %adds new card value to previous hand total
    fprintf("\nDealer's next card is (%s of %s)\n",cards{dealer_shuffle_card1},suit{dealer_shuffle_suit1})
    fprintf("Dealer's total value is %d\n",dealer_total)
end