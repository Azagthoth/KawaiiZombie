#ifndef CONSTANTS_
#define CONSTANTS_

//################################################################
//########################### TEXTS ##############################
//################################################################

#define NURSE String("Nurse")
#define ZOMBIE String("Zombie")
#define DART String("Dart")

#define WORLD_HEIGHT 480 * 3
#define WORLD_WIDTH 800 * 3

#define NURSE_SPEED 2
#define ZOMBIE_SPEED 1
#define NURSE_MAX_LIFE 1

//################################################################
//######################## Actions ID ############################
//################################################################

//################################################################
//########################## Images ##############################
//################################################################

//################################################################
//######################## Controls ##############################
//################################################################

#define K_BUTTON_PLAY 			"IDC_BTN_PLAY"
#define K_BUTTON_SCORE 			"IDC_BTN_SCORE"
#define K_BUTTON_HELP			"IDC_BTN_HELP"
#define K_BUTTON_CREDITS 		"IDC_BTN_CREDITS"
#define K_LABEL_BACKGROUND 		"IDC_LABEL_BKG"


//################################################################
//################ Macros definitions ############################
//################################################################

// Safe and clean delete operator
#define SAFE_DELETE(x) {if (x != null){ \
							delete x;\
							x=null;}\
						}

#define DELETE_COLLECTION(x) {if (x != null) \
							{ 	x->RemoveAll(true);\
								delete x;\
								x=null;} \
							}



#endif
