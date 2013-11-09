//
//  MBProgressHUD.h
//  Yo
//
//  Created by Navraj Singh on 26/12/12.
//  Copyright (c) 2012 Codegen Technologies. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    
    MBProgressHUDModeIndeterminate,
    
	MBProgressHUDModeDeterminate,
	
	MBProgressHUDModeCustomView
} MBProgressHUDMode;

typedef enum {
   
    MBProgressHUDAnimationFade,
   
    MBProgressHUDAnimationZoom
} MBProgressHUDAnimation;

@protocol MBProgressHUDDelegate <NSObject>

@required

- (void)hudWasHidden;

@end

@interface MBRoundProgressView : UIProgressView {}

- (id)initWithDefaultSize;

@end

@interface MBProgressHUD : UIView {
	
	MBProgressHUDMode mode;
    MBProgressHUDAnimation animationType;
	
	SEL methodForExecution;
	id targetForExecution;
	id objectForExecution;
	BOOL useAnimation;
	
    float yOffset;
    float xOffset;
	
	float width;
	float height;
	
	float margin;
	
	BOOL taskInProgress;
	float graceTime;
	float minShowTime;
	NSTimer *graceTimer;
	NSTimer *minShowTimer;
	NSDate *showStarted;
	
	UIView *indicator;
	UILabel *label;
	UILabel *detailsLabel;
	
	float progress;
	
	id<MBProgressHUDDelegate> delegate;
	NSString *labelText;
	NSString *detailsLabelText;
	float opacity;
	UIFont *labelFont;
	UIFont *detailsLabelFont;
	
    BOOL isFinished;
	BOOL removeFromSuperViewOnHide;
	
	UIView *customView;
	
	CGAffineTransform rotationTransform;
}
+ (MBProgressHUD *)showHUDAddedTo:(UIView *)view animated:(BOOL)animated;
+ (BOOL)hideHUDForView:(UIView *)view animated:(BOOL)animated;
- (id)initWithWindow:(UIWindow *)window;
- (id)initWithView:(UIView *)view;
@property (retain) UIView *customView;
@property (assign) MBProgressHUDMode mode;
@property (assign) MBProgressHUDAnimation animationType;
@property (assign) id<MBProgressHUDDelegate> delegate;
@property (copy) NSString *labelText;
@property (copy) NSString *detailsLabelText;
@property (assign) float opacity;
@property (assign) float xOffset;
@property (assign) float yOffset;
@property (assign) float margin;
@property (assign) float graceTime;
@property (assign) float minShowTime;
@property (assign) BOOL taskInProgress;
@property (assign) BOOL removeFromSuperViewOnHide;
@property (retain) UIFont* labelFont;
@property (retain) UIFont* detailsLabelFont;
@property (assign) float progress;

@property (retain) UIView *indicator;
@property (assign) float width;
@property (assign) float height;
@property (retain) NSTimer *graceTimer;
@property (retain) NSTimer *minShowTimer;
@property (retain) NSDate *showStarted;
- (void)show:(BOOL)animated;
- (void)hide:(BOOL)animated;
- (void)showWhileExecuting:(SEL)method onTarget:(id)target withObject:(id)object animated:(BOOL)animated;

- (void)hideUsingAnimation:(BOOL)animated;
- (void)showUsingAnimation:(BOOL)animated;
- (void)fillRoundedRect:(CGRect)rect inContext:(CGContextRef)context;
- (void)done;
- (void)updateLabelText:(NSString *)newText;
- (void)updateDetailsLabelText:(NSString *)newText;
- (void)updateProgress;
- (void)updateIndicators;
- (void)handleGraceTimer:(NSTimer *)theTimer;
- (void)handleMinShowTimer:(NSTimer *)theTimer;
- (void)setTransformForCurrentOrientation:(BOOL)animated;

@end
