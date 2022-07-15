def main(): #the main function is being defined
    choice=eval(input("(1)Team \n(2)Player \n(3)Final \n(4)Exit\n")) #User is given the choice of four options
    while choice==1: #If the user keeps on opting for choice 1
        team1() #Function of team 1 is being called
    while choice==2: #If the user keeps on opting for choice 2
        player1() #Function of player 1 is being called
    while choice==3: #If the user keeps on opting for choice 3
        final() #Function of final is being called
    if choice ==4: #If the user keeps on opting for choice 4
        exit() #Function of exit is being called
def team1(): #Main Function of team is being defined
    choice1=input("(A)Add \n(B)View \n(C)Search \n(D)Update \nE)Menu") #User is given the choice of four options
    if choice1=="A": #If the user keeps on opting for sub choice A
        team1_add() #Function of team1_add is being called
    if choice1=="B": #If the user keeps on opting for sub choice B
        team1_view() #Function of team1_view is being called
    if choice1=="C": #If the user keeps on opting for sub choice C
        team1_search() #Function of team1_search is being called
    if choice1=="D":#If the user keeps on opting for sub choice D
        team1_update() #Function of team1_update is being called
    if choice1=="E": #If the user keeps on opting for sub choice E
        main() #the main function is being called
def team1_add(): #Function of teaam1_add is being defined
    team_id=input("Enter team id: ") #Asks the user to enter the id of the team
    team_name=input("Enter team name: ") #Asks the user to enter the name of the team
    team_coach=input("Enter team coach name: ") #Asks the user to enter the name of the respective coach of team
    team_ranking=input("Enter team ranking: ") #Asks the user to enter the ranking of the team
    team.append(team_id) #Team id is appended in the list of team
    team.append(team_name) #Team name is appended in the list of team
    team.append(team_coach) #Name of the coach of respective team is appended in the list of team
    team.append(team_ranking) #Value of Team ranking is appended in the list of team at index i+1
    choices=input("Enter Yes to go to team menu: ") #Asks the user if he/she wants to continue the program
    if choices=="Yes": #If the user opts for choice of Yes
        team1()#Function of team1 is being called
    elif choices=="No": #If the user opts for the choice of No
        team1_add() #Function of team1_add is being called again
    else: #If the user types any other command
        print("Invalid Command!") #Message of Invalid Command is being displayed
def team1_view(): #Function of team1_view is being defined
    if len(team)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
    else:    #IF the recod has been entered
        print("Team id     Team name     Team Coach name     Team ranking")
        for i in range(0,len(team),4): #Condition of for is being called for the purpose of staying in range of length of list with increment of 4
            
            print(team[i],end="            ") #User is showcased with the team id at the specified index
            print(team[i+1],end="             ") #User is showcased with the team name at the specified index 
            print(team[i+2],end="             ") #User is showcased with the team's coach name at the specified index
            print(team[i+3]) #User is showcased with the team's ranking at the specified index
def team1_search(): #Function of team1_search is being called
 if len(team)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
 else: #IF the record has been entered
    team_id=input("Enter team id: ") #User is asked to enter the value of team id
    for i in range(len(team)): #The statement of for is being executed for the length of the list team
        if team_id==team[i]: #The program checks if the id exists in the list of team
            print("Team id: ",team[i]) #User is showcased with the team id at the specified index
            print("Team name: ",team[i+1]) #User is showcased with the team name at the specified index
            print("Team coach name: ",team[i+2]) #User is showcased with the name of coach of respective team at the specified index
            print("Team  ranking: ",team[i+3]) #Value of team ranking present at the specified index is being showcased
    if team_id not in team: #If the enetered value does not exists in the list of team 
        print("No team of such name found!") #User is showcased with a message that no such team name is found
    choices=input("Enter Yes to go to team menu: ") #User is asked if he wants to return to the main menu of team
    if choices=="Yes": #If users opts for the choice of yes
        team1() #Function of team1 is being called again
    elif choices=="No": #If the user opts for choice of No
        team1_search() #Function of team1_search is being called again
    else: #If the user enters any other value
        print("Invalid Command!") #An error message of Invalid command is being showcased to the user
def team1_update(): #Function of team1_update is being defined
 if len(team)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
 else: #IF the recod has been entered
    team_id=input("Enter team id: ") #User is asked to enter the team id he/she wants to modify
    if team_id not in team: #If the entered team name does not exist in the list
        print("No team of such id found!") #An error message of no such team found is being displayed
    for i in range(len(team)): #For statement is generted for the length of the list of team
        if team_id==team[i]: #If that id is present on any index of the list
            team[i]=input("Enter new team id: ") #User is asked to enter the new team id to replace the previous one
            team[i+1]=input("Enter new team name: ") #User is asked to enter the new team name to replace the previous one
            team[i+2]=input("Enter new coach name:") #User is asked to enter the new coach name of respective team to replace the previous one
            team[i+3]=input("Enter new ranking: ")#Also the user is asked to enter the new ranking accordingly
    choices=input("Enter Yes to go to team menu and No to update again: ") #User is asked if he' she wants to go the main menu of team
    if choices=="Yes": #If user opts for the choice of Yes
        team1() #Function of team1 is being called
    elif choices=="No": #If user opts for the choice of No
        team1_update() #Function of team1_update is being called
    else: #If the user enters any other choice
        print("Invalid Command!") #Error message of invalid command is being displayed
def player1(): #Main Function of player is being defined
    choice1=input("(A)Add \n(B)View \n(C)Search \n(D)Update \nE)Menu") #User is being showcased with the four sub choices again for the function
    if choice1=="A": #If the user keeps on opting for sub choice A
        player1_add() #Function of player1_add is being called 
    if choice1=="B": #If the user keeps on opting for sub choice B
        player1_view() #Function of player1_view is being called 
    if choice1=="C": #If the user keeps on opting for sub choice C
        player1_search() #Function of player1_search is being called 
    if choice1=="D": #If the user keeps on opting for sub choice D
        player1_update() #Function of player1_update is being called 
    if choice1=="E": #If the user keeps on opting for sub choice E
        main() #Main fuction is returned
def player1_add(): #Function of player1_add is being defined
    player_id=input("Enter player id: ") #Asks the user to enter the player's id
    nam=input("Enter player name: ") #Asks the user to enter the player's name
    distinction=input("Enter Distinction: ") #Asks the user to enter the player's distinction
    player_city=input("Enter player city: ") #Asks the user to enter the player's city
    player.append(player_id) #The player's id is appended in the list of player
    player.append(nam) #The player's name is appended in the list of player
    player.append(distinction) #The player's distinction is appended in the list of player
    player.append(player_city) #The player's city name is appended in the list of player

    choices=input("Enter Yes to go to player menu: ") #The user is asked that if he wants to go the player menu
    if choices=="Yes": #If the user opts for the choice of Yes
        player1() #Function of player1 is being called
    elif choices=="No": #If the user opts for the choice of No
        player1_add() #Function of player1_add is being called
    else: #If the user opts for any other choice
        print("Invalid Command!") #Error message of invalid command is being displayed
def player1_view(): #Function of player1_view is being defined
 if len(player)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
 else:  #IF the record has been entered
    for i in range(0,len(player),4): #For statement is executed for the range of length of the list of player with an increment of 4
        print("Player id: ",player[i]) #User is being showcased with the player id at the respective index
        print("Player name: ",player[i+1]) #User is being showcased with the player's name at the respective index
        print("Distinction: ",player[i+2]) #User is being showcased with the player's distinction at the respective index
        print("Player City: ",player[i+3]) #User is being showcased with the player's city at the respective index
def player1_search():#Function of player1_search is being defined
 if len(player)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
 else: #IF the record has been entered
    player_id=input("Enter player id: ") #User is asked to enter the value of id of respective player
    for i in range(len(player)): #For statement is executed for the length of list of players
        if player_id==player[i]: #If the entered id is present at any index of the player list
            print("player id: ",player[i]) #The value of player id at the respective index is being showcased
            print("Player name: ",player[i+1]) #The value of player name at the respective index is being showcased
            print("Player Distinction: ",player[i+2]) #The value of player's distinction at the respective index is being showcased
            print("Player city: ",player[i+3]) #The value of player's city at the respective index is being showcased
    if player_id not in player: #If the entered name is not present in the list
        print("No player record found!") #Error message of No player record found is displayed
    choices=input("Enter Yes to go to player menu: ") #The user is asked that if he wants to go the player menu
    if choices=="Yes": #If the user opts for the choice of Yes
        player1()  #Function of player1 is being called
    elif choices=="No": #If the user opts for the choice of No
        player1_search() #Function of player1_add is being called
    else: #If the user opts for any other choice
        print("Invalid Command!") #Error message of invalid command is being displayed
def player1_update(): #Function of player1_update is being defined
 if len(player)<4: #If the record has not been entered previously
        print("Enter record first!") #Error message of enter record first appears
 else: #IF the record has been entered
    player_id=input("Enter player id: ") #User is asked to enter the player id he/she wants to modify
    if player_id not in player: #If the entered player name does not exist in the list
        print("No player of such name found!") #An error message of no such team found is being displayed
    for i in range(len(player)): #For statement is generated for the length of the list of player
        if player_id==player[i]: #If that id is present on any index of the list
            player[i]=input("Enter new player id: ") #User is asked to enter the new player id to replace the previous one
            player[i+1]=input("Enter new name: ") #Also the user is asked to enter the new name for the player 
            player[i+2]=input("Enter distinction: ") #Also the user is asked to enter the new distinction for the player 
            player[i+3]=input("Enter City: ") #Also the user is asked to enter the new city name for the player 
    choices=input("Enter Yes to go to player menu: ") #User is asked if he' she wants to go the main menu of player
    if choices=="Yes": #If user opts for the choice of Yes
        player1() #Function of player1 is being called
    elif choices=="No": #If user opts for the choice of No
        player1_update() #Function of player1_update is being called
    else: #If the user enters any other choice
        print("Invalid Command!") #Error message of invalid command is being displayed
def final(): #Main Function of final is being defined
    choice=eval(input("(1)Final addition to roster \n(2)View Roster \n(3)Main Menu: ")) #User is being showcased with the four sub choices again for the function
    if choice==1: #If the user keeps on opting for sub choice 1
        final_add() #Function of final_add is being called 
    if choice==2: #If the user keeps on opting for sub choice 2
        final_view() #Function of final_view is being called 
    if choice==3: #If the user keeps on opting for sub choice 3
        main() #Main function is returned
def final_add(): #Function of final_add is being defined
 player_id=input("Enter player id: ") #User is asked to enter the player id he/she wants
 for i in range(len(player)): #For statement is executed for the length of list of players   
        if player_id==player[i]: #If the entered id is present at any index of the player list
            print("Player id: ",player[i]) #User is being showcased with the player id at the respective index
            print("Player name: ",player[i+1]) #User is being showcased with the player's name at the respective index
            print("Distinction: ",player[i+2]) #ser is being showcased with the player's name at the respective index
            print("Player City: ",player[i+3]) #The value at the respective index of i+1 is being showcased
            for i in range(0,len(final_list),2): #For statement is executed for the range of final list with increment of 2
                if player_id in final_list[i+1]: #If player id exist in the length of final list's stark
                    print("This player is already assigned to another team!") #The message is being displayed
            if player_id not in final_list: #If the player id exist in the final list
                    team_id=input("Enter team id: ")#User is asked to enter the team id he/she wants to assign      
                    for j in range(len(team)): #For statement is executed for the length of list of team
                        if team_id==team[j]: #If the entered id is present at any index of the team list
                            if team_id not in final_list: #If team id is not in the final list
                                final_list.append(team_id) #The team id is entered in the final list
                                stark=[] #Empty list is created 
                                stark.append(player_id) #Player id is added in the list of stark
                                stark.append(eval(input("Enter hiring amount: "))) #User is asked to enter hiring amount and that is added in the stark
                                final_list.append(stark) #Stark is added in the final list
                    
                            else: #If team id is present in the final list
                                for i in range(len(final_list)):#For statement is executed for the length of final list
                                    if team_id==final_list[i]: #If team id is present in the final list
                                        if len(final_list[i+1])>=10: #If length of final list is greater than or equal to 10
                                            print("All the spots in team are occupied!") #Message is being displayed
                                        else: #If the length of final list is less than 10
                                            final_list[i+1].append(player_id) #Player id is added in the final lis
                                            final_list[i+1].append(eval(input("Enter hiring amount: "))) #Hiring amount is added in the final list
                    
            
 if player_id not in player: #If the entered player name does not exist in the list
        print("No such player") #Error message of no such player is being displayed
 choices=input("Enter Yes to go to player menu: ")  #User is asked if he' she wants to go the main menu of player
 if choices=="Yes": #If user opts for the choice of Yes
    final() #Function of final() is being called
 elif choices=="No": #If user opts for the choice of No
    final_add() #Function of final_add() is being called
 else: #If user opts for any other choice
    print("Invalid Command!") #An error message of Invalid command is being displayed
    final() #Function of final is being returned

def final_view(): #Function of final_view is being defined
 if len(final_list)<4: #f no record has been entered
        print("Enter record first!") #Error message of enter record first is being displayed
 else: #If the record has been entered previously
    print("Team id   PLayer name   Player hiring amount")
    for i in range(0,len(final_list),2): #For loop for the length of final_list with an increment of 2 is being executed
        
        print(final_list[i],end="              \n") #The value of the team id is being showcased
        for j in range(0,len(final_list[i+1]),2): #For loop for the length of final list with increment of 2 is being executed
            print(final_list[i+1][j],end="              ") #The value of player id is being displayed
            print(final_list[i+1][j+1]) #The value of decided hiring amount is being displayed
final_list=[] #Empty final list is created
player=[] #Empty player list is created
team=[] #Empty team list is created
main() #Function of main is returned




