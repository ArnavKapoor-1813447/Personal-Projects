%this is the leverage function, which asks user if thwey want any leverage
%and multiplies the usercapital by the number inputted. this was the third
%part of the code I added and decided to write it as a seperate function as
%it will make my main driver much more easier to follow and debug
function [user_capital, leverage_value] = offer_leverage(user_capital)
    valid_leverage = false;
    while ~valid_leverage
        user_leverage = input("Actually before we start, I would like to inform you that our humble casino offers leverage ranging up to 25x on your capital, would you like some, press Y/N: ", 's');
        if strcmpi(user_leverage, 'y') % if user wants leverage the following actions are carried out
            leverage_value = input("How much leverage would you like (your leverage can only be a max of 25x and in whole numbers, otherwise we will round it to the nearest number): ");
            leverage_value = max(1, min(25, round(leverage_value))); % makes it so lowest leverage is 1 and highest is 25
            user_capital = user_capital * leverage_value; %increases the user capital by leverage multiplier
            fprintf("Your leverage is %0.02fx and your capital is now $%d\n", leverage_value, user_capital);
            valid_leverage = true;
        elseif strcmpi(user_leverage, 'n')
            leverage_value = 1; 
            valid_leverage = true; % when user answers with 'n', the loop is turned off
        else
            disp('INVALID VALUE, please try again'); % when user answers with an invalid input the, the loop is repeated. 
        end
    end
end
