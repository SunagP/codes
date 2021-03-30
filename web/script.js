function myFunction() { 
            
    var x =  document.getElementById("oname").value; 
    document.getElementById("demo").innerHTML = "Name:"+ x;
   
    
    if(document.getElementById("paya").checked)            
    document.getElementById("rd").innerHTML ="PAYMENT:" + document.getElementById("paya").value;
    if(document.getElementById("payb").checked)            
    document.getElementById("rd").innerHTML ="PAYMENT:" + document.getElementById("payb").value;
    if(document.getElementById("payc").checked)            
    document.getElementById("rd").innerHTML ="PAYMENT:" + document.getElementById("payc").value;
   
    
    if(document.getElementById("ca").checked)            
    document.getElementById("c").innerHTML ="Items:" + document.getElementById("ca").value;
    if(document.getElementById("cb").checked)            
    document.getElementById("c1").innerHTML ="Items:" + document.getElementById("cb").value;
    if(document.getElementById("cc").checked)            
    document.getElementById("c2").innerHTML ="Items:" + document.getElementById("cc").value;
    if(document.getElementById("cd").checked)            
    document.getElementById("c3").innerHTML ="Items:" + document.getElementById("cd").value;
    
} 