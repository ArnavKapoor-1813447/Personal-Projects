% I added the hit/stand loop after I was satisfied with my deck and card
% print outputs. the loop was designed  with while loops and if
% conditionals so it would add another card when user chose hit, do nothing
% when user chose stand and repeat the input message if user put a invalid
% response


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