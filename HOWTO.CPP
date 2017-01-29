#inlcude<iostream.h>
void main()
{
	cout<<"The game starts with asking screen name of both the players i.e. Player 1 and Player 2. Keep in mind that names should not exceed more than 5 characters and no name should start with a numeral.";
	cout<<"\nPress SPACEBAR to proceed. It's Player 1's turn and hit SPACEBAR again to display Player 1's rack.";
	cout<<"\n\nSelect the direction of letter input sequence i.e. down(d) / across(a)";
	cout<<"\n\nAfter selecting the direction, navigate to the desired position on board using direction keys on keyboard.";
	cout<<"\n\nRemember that the very first move of the game should include the center tile (8,8) marked with pink color else you can't proceed.";
	cout<<"\n\nNow, press SPACEBAR twice to start entering the letters from the rack and press SPACEBAR once when done";
	cout<<"\n\nIf the combination of letters are validated by the dictionary as a qualified word, points are awarded accordingly and chance is passed onto another player.";
	cout<<"\n\nFor consecutive chances, each player should make use of at least one letter already placed on the board. For example, if Player 1 had placed the following tiles in this manner:";
	cout<<"\nT I E\nPlayer 2 should place the tiles either by using T or I or E or all of them. For instance, following are valid combinations:";
	cout<<"\nT I E R\nI\nT I E\nT I E\n  N";
	cout<<"\n\nIf a player is unable to form a word from given set of tiles, he/she loses.";
	cout<<"\n\nThe end of game is marked by finishing off letters from the tile or in case of game forfeited by any player.";
	cout<<"\n\nFor information on points awarding scheme and frequency of letter tiles in the game, refer to ABOUT GAME section in the main menu.";
	cout<<"\n\nHappy Gaming!";
}

