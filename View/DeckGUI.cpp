#include "DeckGUI.h"
#include <algorithm>
#include <iterator>
#include <string>
using std::string;
using std::transform;

const char * image_names[] = {
	"cards_png/0_0.png",
	"cards_png/0_1.png",
	"cards_png/0_2.png",
	"cards_png/0_3.png",
	"cards_png/0_4.png",
	"cards_png/0_5.png",
	"cards_png/0_6.png",
	"cards_png/0_7.png",
	"cards_png/0_8.png",
	"cards_png/0_9.png",
	"cards_png/0_j.png",	
	"cards_png/0_q.png",
	"cards_png/0_k.png",
	"cards_png/1_0.png",
	"cards_png/1_1.png",
	"cards_png/1_2.png",
	"cards_png/1_3.png",
	"cards_png/1_4.png",
	"cards_png/1_5.png",
	"cards_png/1_6.png",
	"cards_png/1_7.png",
	"cards_png/1_8.png",
	"cards_png/1_9.png",
	"cards_png/1_j.png",
	"cards_png/1_q.png",	
	"cards_png/1_k.png",
	"cards_png/2_0.png",
	"cards_png/2_1.png",
	"cards_png/2_2.png",
	"cards_png/2_3.png",
	"cards_png/2_4.png",
	"cards_png/2_5.png",
	"cards_png/2_6.png",
	"cards_png/2_7.png",
	"cards_png/2_8.png",
	"cards_png/2_9.png",
	"cards_png/2_j.png",
	"cards_png/2_q.png",	
	"cards_png/2_k.png",
	"cards_png/3_0.png",
	"cards_png/3_1.png",
	"cards_png/3_2.png",
	"cards_png/3_3.png",
	"cards_png/3_4.png",
	"cards_png/3_5.png",
	"cards_png/3_6.png",
	"cards_png/3_7.png",
	"cards_png/3_8.png",
	"cards_png/3_9.png",
	"cards_png/3_j.png",	
	"cards_png/3_q.png",
	"cards_png/3_k.png",
	"cards_png/nothing.png"
};

// Loads the image from the specified file name into a pixel buffer.
Glib::RefPtr<Gdk::Pixbuf> createPixbuf(const string & name) {
	return Gdk::Pixbuf::create_from_file( name );
} 

DeckGUI::DeckGUI()  {
	// Images can only be loaded once the main window has been initialized, so cannot be done as a static
	// constant array. Instead, use the STL transform algorithm to apply the method createPixbuf to every
	// element in the array of image names, starting with first and ending with the last. New elements are
	// added to the back of deck.
	transform( &image_names[0], &image_names[G_N_ELEMENTS(image_names)],
			   std::back_inserter(deck), &createPixbuf );
}

DeckGUI::~DeckGUI() {
}

// Returns the image for the specified card.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::image( Rank f, Suit s ) {
	int index = ((int) f) + ((int) s )*13;
	return deck[ index ];
}

const char* DeckGUI::imageName(Rank f, Suit s) {
	int index = ((int) f) + ((int) s )*13;
	return image_names[index];
}



// Returns the image to use for the placeholder.
Glib::RefPtr<Gdk::Pixbuf> DeckGUI::null() {
	int size = deck.size();
	return deck[ size-1 ];
}
