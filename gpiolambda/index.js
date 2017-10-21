// Alexa SDK for JavaScript v1.0.00
// Copyright (c) 2014-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved. Use is subject to license terms.


var pubnub = require("pubnub")({
    ssl           : true,  
    publish_key   : "pub-c-7aed85e3-ecbe-48e7-9dad-538f6b815a9e",
    subscribe_key : "sub-c-18fdcb54-b675-11e7-97d2-5eb2fdfa058b"
});

var channel = 'hello_world';

/**
 * App ID for the skill
 */
var APP_ID = 'amzn1.ask.skill.a58753be-5dbd-4342-86e5-444a6924a0dd'; 

/**
 * The AlexaSkill prototype and helper functions
 */
var AlexaSkill = require('./AlexaSkill');

/**
 * Echobot is a child of AlexaSkill.
 * To read more about inheritance in JavaScript, see the link below.
 *
 * @see https://developer.mozilla.org/en-US/docs/Web/JavaScript/Introduction_to_Object-Oriented_JavaScript#Inheritance
 */


//////

var GPIOControl = function () {

    AlexaSkill.call(this, APP_ID);
};


// Extend AlexaSkill
GPIOControl.prototype = Object.create(AlexaSkill.prototype);
GPIOControl.prototype.constructor = GPIOControl;

AlexaSkill.prototype.eventHandlers = {
	onLaunch: function (launchRequest, session, response) {
   		console.log("Session:", session);
        response.tell("Welcome to PUMPKIN!");
    }
};


GPIOControl.prototype.intentHandlers = {
    // register custom intent handlers
   // TurnOn: function (intent, session, response) {
	  //  var gpioNum = 0;
	  //  if (intent.slots.GPIO) {
	  //  	gpioNum = intent.slots.GPIO.value;
	  //  }
	  //  var message = {
	  //           "action"   : 1,
	  //           "GPIO": gpioNum
	  //       };
	  //   pubnub.publish({ 
	  //       channel   : channel,
	  //       message   : message,
	  //       callback  : function(e) { 
	  //            console.log("SUCCESS!", e); 
	  //            response.tell("Turning on " + gpioNum);
	  //       },
	  //       error     : function(e) { 
	  //           console.log("failed", e); 
	  //       }
	  //   });          
   //  },
   
   Yes: function(intent, session, response) {
   	var message = {
   		"action": 1
   	}
   	pubnub.publish({
   		channel: channel,
   		message: message,
   		callback: function(e) {
   			console.log("Success!", e);
   			response.tell("Go ahead and take some candy");
   		},
   		error: function(e) {
   			console.log("Failed", e);
   		}
   	});
   },
   No: function(intent, session, response) {
   	var message = {
   		"action": 1
   	}
   	pubnub.publish({
   		channel: channel,
   		message: "No",
   		callback: function(e) {
   			console.log("Success!", e);
   			response.tell("That's a bummer");
   		},
   		error: function(e) {
   			console.log("Failed", e);
   		}
   	});
   },
   // TurnOff: function (intent, session, response) {
	  //  var gpioNum = 0;
	  //  if (intent.slots.GPIO) {
	  //  	gpioNum = intent.slots.GPIO.value;
	  //  }
	  //  var message = {
	  //           "action"   : 2,
	  //           "GPIO": gpioNum
	  //       };
	  //   pubnub.publish({ 
	  //       channel   : channel,
	  //       message   : message,
	  //       callback  : function(e) { 
	  //            console.log("SUCCESS!", e); 
	  //            response.tell("Turning off" + gpioNum);
	  //       },
	  //       error     : function(e) { 
	  //           console.log("failed", e); 
	  //       }
	  //   });          
   //  },
   //  AllOn: function (intent, session, response) {
	  //  var message = {
	  //           "action"   : 3
	  //       };
	  //   pubnub.publish({ 
	  //       channel   : channel,
	  //       message   : message,
	  //       callback  : function(e) { 
	  //            console.log("SUCCESS!", e); 
	  //            response.tell("Turning all on");
	  //       },
	  //       error     : function(e) { 
	  //           console.log("failed", e); 
	  //       }
	  //   });          
   //  },
   //  AllOff: function (intent, session, response) {
	  //  var message = {
	  //           "action"   : 4
	  //       };
	  //   pubnub.publish({ 
	  //       channel   : channel,
	  //       message   : message,
	  //       callback  : function(e) { 
	  //            console.log("SUCCESS!", e); 
	  //            response.tell("Turning all off");
	  //       },
	  //       error     : function(e) { 
	  //           console.log("failed", e); 
	  //       }
	  //   });          
   //  },
    default: function (intent, session, response) {
        response.ask("Try again");
    },
    
};


// Create the handler that responds to the Alexa Request.
exports.handler = function (event, context) {

    // Create an instance of the Echobot skill.
    var gpiocontrol = new GPIOControl();
    gpiocontrol.execute(event, context);
    

};
