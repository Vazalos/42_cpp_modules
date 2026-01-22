/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 16:39:47 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/20 13:48:49 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << '\n';
        
    ideas[0] = "Is that a bug? I must pounce.";
    ideas[1] = "This box is mine now.";
    ideas[2] = "Why is the human touching me? Ugh.";
    ideas[3] = "Oh, you're sleeping? Perfect time to run across the room at top speed.";
    ideas[4] = "Feed me. Now.";
    ideas[5] = "Pet me… but not there!";
    ideas[6] = "Bow to me, mortal.";
    ideas[7] = "I could fit in that tiny space.";
    ideas[8] = "That red dot will be mine one day.";
    ideas[9] = "I see you've put your clothes here. Time to cover them in fur.";
    ideas[10] = "Why is the small human screaming?";
    ideas[11] = "This looks like a great spot to nap.";
    ideas[12] = "Knock-knock. Whoops, your glass is falling.";
    ideas[13] = "You look busy—I'll sit on your keyboard.";
    ideas[14] = "This hand is for me to bite.";
    ideas[15] = "Why do doors exist? They hinder my freedom.";
    ideas[16] = "Oh, you’re sitting down? Let me curl up on you.";
    ideas[17] = "Strings are life.";
    ideas[18] = "Where's the sunbeam? I need to recharge.";
    ideas[19] = "Did you seriously move that chair? It's wrong now.";
    ideas[20] = "You can't see me if I close my eyes.";
    ideas[21] = "This is MY house. You're just visiting.";
    ideas[22] = "I bet I can jump up there.";
    ideas[23] = "Why do you keep touching my beans?";
    ideas[24] = "I'll make you pay for leaving me alone.";
    ideas[25] = "Why are there no snacks in this bowl?";
    ideas[26] = "I was awake all night. Time to nap all day.";
    ideas[27] = "You're such a clumsy servant.";
    ideas[28] = "Will this plastic bag taste good?";
    ideas[29] = "What’s in this bag? Let me dig through it.";
    ideas[30] = "Laundry day! My new bed!";
    ideas[31] = "I’m not ignoring you; I’m just better than you.";
    ideas[32] = "That bird outside needs to be eliminated.";
    ideas[33] = "Stop looking at me.";
    ideas[34] = "Is that for me? Oh, it’s for you? That’s mine anyway.";
    ideas[35] = "This is my box. Get your own.";
    ideas[36] = "Hmm… another human… I will observe from afar.";
    ideas[37] = "You didn’t need this plant. It’s on the floor now.";
    ideas[38] = "Why does everyone scream when I bring them a dead thing? Don’t they like presents?";
    ideas[39] = "Your laptop was cold, but I warmed it up for you.";
    ideas[40] = "Yes, I climbed up here. No, I can’t get down.";
    ideas[41] = "Why do you love the dog more than me?";
    ideas[42] = "You’re awake! Hooray! Feed me!";
    ideas[43] = "I don’t trust that vacuum.";
    ideas[44] = "My tail is worth chasing.";
    ideas[45] = "I showed you my belly; pay tribute!";
    ideas[46] = "I rule this house.";
    ideas[47] = "Why do you wiggle your finger like the red dot? Impostor.";
    ideas[48] = "Ah, the sound of kibble pouring… my soul is at peace.";
    ideas[49] = "I’m not hiding—I’m studying my prey.";
    ideas[50] = "Human! Human! You came back!";
    ideas[51] = "Is that food? Can I have it?";
    ideas[52] = "The ball! Throw the ball!";
    ideas[53] = "You look sad. Let me fix that!";
    ideas[54] = "Your love is all I need… and maybe that snack.";
    ideas[55] = "Can I go outside now? Please?";
    ideas[56] = "The leash means walk time!";
    ideas[57] = "I hear something! Must bark!";
    ideas[58] = "You called my name? I love you!";
    ideas[59] = "What’s this? What’s this? Smells interesting!";
    ideas[60] = "New person! I LOVE you already!";
    ideas[61] = "I’m the goodest boy!";
    ideas[62] = "The mailman’s here! ALERT! ALERT!";
    ideas[63] = "Oh no, the doorbell! Intruder? I must protect!";
    ideas[64] = "I will follow you even to the bathroom.";
    ideas[65] = "Look, I did a circle! Aren’t I the best?";
    ideas[66] = "Sleep with one eye open, squirrel.";
    ideas[67] = "Don’t look at the cat. Look at ME.";
    ideas[68] = "What’s this ‘personal space’ you speak of?";
    ideas[69] = "Oh boy, food time again!";
    ideas[70] = "Oh no, they’re leaving without me again.";
    ideas[71] = "You’re on the couch; can I sit there too?";
    ideas[72] = "Pet my head. Keep petting. Don’t stop.";
    ideas[73] = "Whatever you’re eating smells better than mine.";
    ideas[74] = "You’re my best friend, human.";
    ideas[75] = "Please drop it. Drop it. DROP IT… Food!";
    ideas[76] = "I saw a bird earlier. Danger level: medium.";
    ideas[77] = "Stick? STICK! Let’s play fetch!";
    ideas[78] = "You’re mad at me? Why?";
    ideas[79] = "Everything smells AMAZING!";
    ideas[80] = "Car ride! Car ride! Car ride!";
    ideas[81] = "The park is calling my name!";
    ideas[82] = "Why does the cat never play with me?";
    ideas[83] = "Who’s a good dog? That’s me!";
    ideas[84] = "Oh no, bath time!";
    ideas[85] = "I just wanna be near you forever.";
    ideas[86] = "Rolling in the mud is my favorite thing!";
    ideas[87] = "Look what I found! Is this yours?";
    ideas[88] = "Squirrel! Chase! Chase!";
    ideas[89] = "The good smells are coming from the food thing.";
    ideas[90] = "Can we please go somewhere? Anywhere!";
    ideas[91] = "I did a poo! Look at it!";
    ideas[92] = "My human is literally the best human.";
    ideas[93] = "The cat is glaring at me again… let’s be friends!";
    ideas[94] = "That’s my bed now… your pillow smells better!";
    ideas[95] = "Do you even realize how much I love you?";
    ideas[96] = "I will protect you with my life.";
    ideas[97] = "Tummy rubs mean happiness.";
    ideas[98] = "Can we just play forever and ever?";
    ideas[99] = "My tail is following me again!";
}

Brain::Brain(const Brain& origBrain)
{
    std::cout << "Brain copy assignment called" << '\n';
    for(unsigned int i = 0; i <= 99; i++)
        ideas[i] = origBrain.ideas[i];
}

Brain& Brain::operator=(const Brain& origBrain)
{
    std::cout << "Brain copy operator called" << '\n';
    for(unsigned int i = 0; i <= 99; i++)
        ideas[i] = origBrain.ideas[i];
    return(*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << '\n';
}