const mongoose = require('mongoose');

mongoose.connect('mongodb://localhost:27017/sunagtest');
mongoose.connection.once('open',function(){
    console.log("con has been made");
}).on('error',function(error){
    console.log('error is:')

});