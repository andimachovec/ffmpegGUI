/*
 * Copyright 2022-2023. All rights reserved.
 * Distributed under the terms of the MIT License.
 *
 * Andi Machovec (BlueSky), andi.machovec@gmail.com, 2023
*/


#ifndef CROPVIEW_H
#define CROPVIEW_H

#include <StringList.h>
#include <View.h>

class BBitmap;
class BString;
class BMessenger;

enum {
	CV_UPDATE_CROPVALUES = 'cv00',
	CV_ACTION_DRAW,
	CV_ACTION_MOVE,
};


class CropView : public BView {
public:
				CropView(BMessenger* updateTarget);

	void		Draw(BRect updateRect);
	void 		LayoutChanged();
	void 		MouseDown(BPoint where) override;
	void 		MouseUp(BPoint where) override;
	void 		MouseMoved(BPoint where, uint32 code, const BMessage* dragMessage) override;

	status_t	LoadImage(const char* path);

	void		SetLeftCrop(int32 leftcrop);
	void		SetRightCrop(int32 rightcrop);
	void		SetTopCrop(int32 topcrop);
	void		SetBottomCrop(int32 bottomcrop);
	void		SetEnabled(bool enabled);


private:
	void		_SetDrawingRect();
	void 		_SetMarkerRect();
	void 		_UpdateCropParams();
	bool		_IsOverBorder(BPoint point, BRect rect);

	BBitmap*	fCurrentImage;
	bool		fImageLoaded;
	BSize		fImageSize;
	BRect 		fDrawingRect;
	BRect 		fMarkerRect;
	float		fResizeFactor;

	int32 		fLeftCrop;
	int32 		fRightCrop;
	int32 		fTopCrop;
	int32 		fBottomCrop;
	bool 		fEnabled;

	bool		fMouseDown;
	BPoint		fMarkerTopLeftPoint;
	uint32		fMouseAction;

	BMessenger* fUpdateTarget;
};

#endif
