var drink = "latte";
var ounce = 12;
var shots = 2;

var price;
var taxRate = 0.088;

if (drink == "espresso")
  price = 1.40;
if (drink == "latte" || drink == "cappuccino") {
  if (ounce == 8)
     price = 1.95;
  if (ounce == 12)
     price = 2.35;
  if (ounce == 16)
     price = 2.75;
}

if (drink == "Americano")
  price = 1.20 + 0.30*(ounce/8);
price = price + (shots - 1)*.50;
price = price + price*taxRate;

