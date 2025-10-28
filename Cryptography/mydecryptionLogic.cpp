// just a different formula 
/*
if(isalpha(text.at(i))){

        if(isupper(text.at(i))){
        // so we are basically saying if we have a upper case Z, instead of going to [, go to A, then do the job, and there's a special formula for that.
        cipher.at(i) = ((text.at(i) - 'A' + key) % 26) + 'A'; 
    }
     else if(islower(text.at(i))){
// so we are basically saying if we have a lower case z, instead of going to {, go to a, then do the job, and there's a special formula for that.
        cipher.at(i) = ((text.at(i) - 'a' + key) % 26) + 'a';
     }
    }

    */