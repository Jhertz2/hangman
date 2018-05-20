#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {

int scorecounter=0; //will be used to determine who wins.
int counter=0;

	char phrase[100];//this will store Player 1's phrase

string player1;
string player2;

cout<<"\t\t\t***ECE114 Two Player Hangman***\n"<<endl; // header

cout<<"The rules are simple. Player 1 will make up the phrase. The phrase can consist of any numbers,\n"
		"symbols, upper case letters, or lower case letters. Any non-alphabetic characters will be \n"
		"displayed to the guesser. Player 2 will have to guess. Player 2 will have 10 attempts to guess\n"
		"the correct letters. He or she may only guess single letters. If they type two letters, only the first\n"
		"one will be accepted. If the guess is correct, it will be displayed on the template. Do not worry\n"
		"about upper case or lower case at all, the program will take care of that. If after 10 guesses\n"
		"player 2 hasn't figured it out, they will get one last guess at the entire phrase."<<endl;

		cout<<"\nPlayer 1 will make up the phrase. Player 1, enter your name: ";
getline(cin, player1); // get the player's names for user friendly program
cout<<"\n";
cout<<"Player 2 will be guessing. Player 2, enter your name: "<<endl;
getline(cin, player2);


	cout<<player1<<" enter your phrase ("<<player2<<" look away!):";
	cin.getline(phrase,100);
	cout<<"\n\n\n\n\n\n\n";//this is so player 2 can't see what player 1 entered
	int rounds= strlen(phrase);//to be used in for loops
	int i;

	char temp[rounds];
	for(i=0; i<rounds; i++){

		/* This for loop displays the template for the phrase.
If the value of the character is a letter, it will print a '_'
the phrase and template arrays will have the same number of elements.
 This for loop is essentially copying the phrase in to the temp array,
  but in place of the letters we will put '_'.
  Numbers and other symbols will be displayed to the guesser in the template
*/

		if(phrase[i]==' '){
			cout<<"  "; //if the character is a space, we will store the space to the template.
			temp[i]=' ';

		}
		//ascii code to check if its a symbol or number
		else if((phrase[i]>=33 && phrase[i]<=64) || (phrase[i]>=91 && phrase[i]<=96) ||(phrase[i]>=123 && phrase[i]<=126) ){
			cout<<phrase[i]; //if the array is a symbol or a letter, print it and store it in the array. We want our user only having to guess letters.
			temp[i]=phrase[i];
counter+=1;//we will compare the total value of this counter to the total value of scorecounter
		}

		else {//if the array element isn't a space or a symbol, we will replace it with (AKA if its a capital or lowercase letter) '_'
			cout<<"_ ";
			temp[i]='_';
counter+=1;
		}

/* by incrementing the counter every time its a letter, number, or symbol, we can determine how many
 * non-space characters it has. Later we can compare the number of non space characters in the updated template.
 */


}
char letters[50]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int choices=strlen(letters);
//This will keep track of the player's guesses.



cout<<"\n\nAvailable letters:"; // this loop prints out the available letters player 2 has to choose from.
		for(int z=0; z<choices; z++){
cout<< letters[z]<<" ";
		}



int z,j;
char guess[10];//this array will store the user's guesses.
for(z=0; z<10; z++){//player 2 has 10 guesses to guess the phrase correctly.

	cout<<"\n\n"<< player2<< "'s guess "<< z+1<< " :"<<endl;
	while (((cin>>guess[z]) && cin.ignore() && !isalpha(guess[z])) || (guess[z]==guess[z-1]
|| guess[z]==guess[z-2] || guess[z]==guess[z-3] || guess[z]==guess[z-4] || guess[z]==guess[z-5]
|| guess[z]==guess[z-6] || guess[z]==guess[z-7] ||  guess[z]==guess[z-8] ||  guess[z]==guess[z-9] ||  guess[z]==guess[z-10])){
		//stores the user's guess each time, input validation to make sure they enter a letter.

		cin.clear();
		cout<<"Sorry, you can only guess a letter and that letter cannot have been used before. Try again: "<<endl;


	}

for(j=0; j<rounds; j++){

	if (phrase[j]==guess[z] ||phrase[j]==(guess[z]+32)||phrase[j]==(guess[z]-32)){//using ascii code to make sure it's not case sensitive

		temp[j]=phrase[j];
/*this if statement is updating the array. If any character in the phrase array is equal to
player 2's guess(capital or lowercase) we will change the cooresponding spot in the template array
to that letter. We can do this since the template array and the phrase array have the same number of elements.
 */
	}



	for (int x=0; x<choices; x++){
	if((guess[z]==letters[x]) || (guess[z]==letters[x]-32)|| (guess[z]==letters[x]+32)){
		letters[x]=' ';
		/* this if statement updates the avaiable lettes.For every guess the user has
we will replace the spot of that letter in the "available letter" list with a space,
effectively removing it from the available options*/

		}

}

}
cout<<"\n";
for (int p=0; p<rounds; p++){

	cout<<temp[p]<<" "; // this prints out the updated template



	}

for(int m=0; m<rounds; m++){
	if(temp[m]!=' ' && temp[m]!='_'){
		scorecounter+=1;

		/* this if statement checks to see the score of the game. If the updated template has characters that
arent a space or '_' then we will increase the score counter by 1 for each element. (AKA elements that
are letters or numbers or symbols*/

	}
}

if(scorecounter==counter){

	cout<<"\n\n"<<player2<<" wins!";
	break;

	/*This is how we determine if player 2 wins. If the number of non-space and non '_' characters in the template array
	is equivalent to that in the phrase, player 2 wins. Essentially, if the updated template says the same thing as the original
	phrase, we break the for loop and the player 1 wins.
	*/

}
else{

	scorecounter=0;

	//This resets the score counter each time
}



cout<<"\t"<<10-(z+1)<< "   rounds left";//this displays how many rounds are left
cout<< "\n\nAvailable Letters: ";//this will print which letters remain.

for(int k=0; k<choices; k++){
cout<<letters[k]<<" ";


		}


}





if(scorecounter==0){ // after the 10 rounds, if player 2 couldn't guess the right letters, they get one more guess

	char finalguess[100];
	cout<<"\n\n\n"<<player2<<" this is the last chance! Please guess the phrase: ";
	cin.getline(finalguess,100);
	int finalguesscounter=0;


for(int w=0; w<rounds; w++){

	if((finalguess[w]==phrase[w]) || (finalguess[w]==phrase[w]+32)|| (finalguess[w]==phrase[w]-32)){
		finalguesscounter+=1;//if the final guess element iss the same as the phrase element (capital or lowercase) increment the counter.
	}
}



if(finalguesscounter==(rounds)){//if the final guess counter is the same size as the number of elements in the array
	cout<<"\nThat was correct! "<<player2<<" wins!";
}


if(scorecounter==0 && finalguesscounter!=(rounds) && finalguesscounter!=0){
	cout<<"\n\nSorry that was incorrect. The correct phrase was: '";

		cout<<phrase;//prints the correct phrase
	cout<<"'\n\n"<<player1<<" wins!";
	}

}

cout<<"\n\nGame over. Thanks for playing!";
	return 0;
}
