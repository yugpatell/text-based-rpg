 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# \<Text-Based RPG\>
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Yug Patel](https://github.com/yugpatell)\>  \<[Thomas Tran](https://github.com/TimusTrun)\> \<[Scott Mesdjian](https://github.com/scottmez)\> 
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.
 

## Project Description
> Game Design has always been a topic that interested us. This project would be a stepping stone, not only to demonstrate our ability of using C++ but, into professional game development and working cohesively in a group. C++ is the main language that will be used to create this project. GoogleTest is utilized to perform several unit tests. **Singleton** - The character class illustrates the singleton pattern because it keeps track of the single character and makes sure there is only one at a time. We picked the singleton pattern because we knew that there would only ever need to be one character at a time. We also thought that implementing this pattern would help protect against possible bugs where more than one character was created. 
**Strategy** -  The “attack()” function within the parent class of character and mob will change depending on the type of object created during runtime. This illustrates how an object's behavior will vary depending on the execution of the algorithm in context of the object. It will allow us to select an algorithm that will match with what character that is created.
**Factory** - Different factories would be created depending on the chosen character. These factories would decide which weapon subclass to implement. For example, the archer weapon subclass would be chosen if the archer was the chosen character class.  

 > ## Phase II  
 ## Class Diagram
> ![SINGLETON](https://user-images.githubusercontent.com/66883374/99351868-6ca54100-2856-11eb-89e7-36157e47fe67.png)  
> ![STRATEGY](https://user-images.githubusercontent.com/57920851/99177857-3931ad80-26c2-11eb-92c8-e471043001f8.png)  
> ![ABSTRACTFACTORY](https://user-images.githubusercontent.com/57920851/99177861-42227f00-26c2-11eb-9908-cd71d37aecdb.png)  
> Refer to the descriptions above that describe how each pattern will be implemented in our project.
 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application  
 ![Output](https://user-images.githubusercontent.com/57920851/99169077-b3aaff00-26bb-11eb-83be-1498b580d982.png)<br/>
The output will look like this when the game starts and it will prompt the user for input everyday. As of now, the game will end whenever the user reaches 20 days or the character dies.
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
