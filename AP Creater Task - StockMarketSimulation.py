numb = 0
event1 = {
    "price change Apple": 0.8,
    "price change Saudi Aramco": 0.7,
    "event detail":"The CEO of the company you have invested is not feeling well."
}

event2 = {
    "price change Apple": 1,
    "price change Saudi Aramco": 2,
    "event detail":"USA Government announced that they will stop investment for eco-friendly energy."
}

event3 = {
    "price change Apple": 3,
    "price change Saudi Aramco": 0.5,
    "event detail": "Covid-19 pandemic has started!" 
}

event4 = {
    "price change Apple": 0.9,
    "price change Saudi Aramco": 4,
    "event detail":"Russia invaded Ukraine!"
}

event5 = {
    "price change Apple": 0.01,
    "price change Saudi Aramco": 0.01,
    "event detail": "Mr. Gunn is elected as US president!"
}
event_list = [event1, event2, event3, event4, event5]
Apple = 1
Saudi_Aramco = 2
print("Welcome to stock market simulation.")
print("You will be chosing between Apple and Saudi Aramco as a company you will invest.")
print("You will encounter 5 random events. You can rather choose to invest or not.")
a = int(input("Type 1 for Apple and 2 for Saudi Aramco."))
money = int(input("How much do you want to invest?"))
start_money = money
company = "company"

if a == 1:
    numb = Apple
elif a == 2:
    numb = Saudi_Aramco

for i in range (5):
    print(event_list[i]["event detail"])
    more_or_not = input(str("would you like to invest? type yes or no"))
    if numb == 1:
        if more_or_not == "yes":
            money = float(money) * float(event_list[i]["price change Apple"])
        if more_or_not == "no":
            money = money * 1
    if numb == 2:
        if more_or_not == "yes":
            money = money * event_list[i]["price change Saudi Aramco"]
        if more_or_not == "no":
            money = money * 1
    print(money)

print("The following is the result of your investment.")
print("You have started with... ", end = '')
print(start_money, end = '')
print(" dollars.")
print("And your account balance after the investment is... ", end='')
print(money, end='')
print(" dollars.")
print("Your account balance has increased or decreased by... ")
print(int(money - start_money), end='')
print(" dollars.")
