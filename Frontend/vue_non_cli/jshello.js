function validate(field, elerttext){
    with(field){
        if(value == null || value == ""){
            alert(alerttext);
            return false;
        }else{
            return true;
        }
    }
}

function validate_form(thisform){
with (thisform)
  {
  if (validate(email,"Email must be filled out!")==false)
    {email.focus();return false}
  }
}

function myalert(){
    alert("sdf");
}

