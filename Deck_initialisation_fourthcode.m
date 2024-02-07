% I finally started on the actual game code and started with making the
% deck and dealing the initial cards. I decided to randomly pick the values
% and suits from vectors rather than using 52(or more) different cases as i believd
% this was far more efficient and seeing that most casinos use 4-6 decks
% for blackjack with constant reshuffling, this method would achieve equal if not more
% accurate results due to the complete randomness of cards
% however i would switch methods, if i ever wanted to try making a complex
% card-counting function

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