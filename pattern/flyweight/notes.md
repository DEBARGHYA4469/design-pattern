
### Flyweight Design Pattern 

- Say you have designed a game, where there are multiples flying bullets (~1e6 or more) 
- You have a bullet class called Bullet : {color, image, coordinate, speed, id, weight, type}. 
- Now as the game progresses and new bullets gets created you will exceed the limited memory. 
- One way to optimize the memory is to separate out the intrinsic params like {type, weight, color, image} of the bullet in to separate class : Flyweight. 
- Now the FlyWeightFactory will only maintain a standard collection of 3 or 4 types of bullets used in the game and optimise the space used in the game. 

Idea: If you have a class which has multiple objects, separate out the common params to a separate Class. 