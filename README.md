![CI](https://github.com/cs100/final-project-smesd001-ypate030-ttran419/workflows/CI/badge.svg?branch=master)
# Text-Based RPG

 > Authors: \<[Yug Patel](https://github.com/yugpatell)\>  \<[Thomas Tran](https://github.com/TimusTrun)\> \<[Scott Mesdjian](https://github.com/scottmez)\> 
## Phase I 
 ## Project Description
> Game Design has always been a topic that interested us. This project would be a stepping stone, not only to demonstrate our ability of using C++ but, into professional game development and working cohesively in a group. C++ is the main language that will be used to create this project. GoogleTest is utilized to perform several unit tests. **Singleton** - The character class illustrates the singleton pattern because it keeps track of the single character and makes sure there is only one at a time. We picked the singleton pattern because we knew that there would only ever need to be one character at a time. We also thought that implementing this pattern would help protect against possible bugs where more than one character was created. 
**Strategy** -  The “attack()” function within the parent class of character will change depending on the type of character created during runtime. This illustrates how an object's behavior will vary depending on the execution of the algorithm in context of the object. It will allow us to select an algorithm that will match with what character that is created.
**Factory** - Different factories would be created depending on the chosen character. These factories would decide which weapon subclass to implement. For example, the archer weapon subclass would be chosen if the archer was the chosen character class.  

## Phase II  
 ## Class Diagram
> ![SINGLETON](https://user-images.githubusercontent.com/57920851/101395658-1c326980-387f-11eb-9103-0b3d2992b1c1.png)  
> ![STRATEGY](https://user-images.githubusercontent.com/57920851/101395681-23f20e00-387f-11eb-89ff-57e815ce1d4a.png)  
> ![ABSTRACTFACTORY](https://user-images.githubusercontent.com/57920851/101395603-07ee6c80-387f-11eb-8b4c-980831c16486.png)  
> Refer to the descriptions above that describe how each pattern will be implemented in our project.
 
 ## Phase III
  ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
  ## Screenshots
 > Screenshots of the input/output after running your application
 
 > ![Welcome Screen](https://user-images.githubusercontent.com/57920851/101397482-982db100-3881-11eb-976a-76303980bb7d.PNG)
   *Welcome screen when user runs the game.*
 
 > ![Start Game](https://user-images.githubusercontent.com/57920851/101397561-b398bc00-3881-11eb-8afa-9bd2187af252.PNG)  
  *Beginning of the game after user select name and character.*
  
 > ![Fight Option](https://user-images.githubusercontent.com/57920851/101397623-ca3f1300-3881-11eb-8af8-87192c3f96eb.PNG)  
    *Fight menu when user selects "fight" option in menu.*  
    
  -  ![Fight Win](https://user-images.githubusercontent.com/57920851/101397677-dc20b600-3881-11eb-9d90-4b754a157ddc.PNG)  
     *Output when user wins fight vs mob.*  
    
> ![Explore Option](https://user-images.githubusercontent.com/57920851/101397779-fe1a3880-3881-11eb-876d-ec77ebf1fa9f.PNG)  
 *Explore menu when user selects "explore" option in menu.*
   
> ![Access Inventory Option](https://user-images.githubusercontent.com/57920851/101397869-1e49f780-3882-11eb-96d4-81ff475bc952.PNG)  
 *Access Inventoy menu when user selects "access inventory" option in menu.*

   - ![Equipment](https://user-images.githubusercontent.com/57920851/101398062-649f5680-3882-11eb-8c70-ff764faf862c.PNG)  
     *Output when user selects "equipment" in access inventory menu.*
    
   - ![Consumables](https://user-images.githubusercontent.com/57920851/101398152-7ed93480-3882-11eb-9ece-9900aa9be184.PNG)  
     *Output when user selects "consumables" in access inventory menu.*
   
> ![Heal Option](https://user-images.githubusercontent.com/57920851/101397849-168a5300-3882-11eb-95c4-c1fd07f34923.PNG)  
  *Output when user selects "heal" option in menu.* 

 ## Installation/Usage
 > Generate the makefile to run the game
 
     $ cmake .
  
 > Generate the file to run the game
 
     $ make
     
 > Run the game
     
     $ ./text-based-rpg
     
