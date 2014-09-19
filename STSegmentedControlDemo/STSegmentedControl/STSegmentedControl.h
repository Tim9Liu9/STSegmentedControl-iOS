//
//  STSegmentedControl.h
//  STSegmentedControl
//
//  Version: 1.0
//
//  Created by Cedric Vandendriessche on 10/11/10.
//  Copyright 2010 FreshCreations. All rights reserved.
//

#import <Foundation/Foundation.h>

#define STSegmentedControlHeight 30.0 // the height of the control. Change this if you're making controls of a different height

enum {
    STSegmentedControlNoSegment = -1 // segment index for no selected segment
};

@interface STSegmentedControl : UIControl

@property (nonatomic, strong) NSMutableArray *segments; // at least two (2) NSStrings are needed for a STSegmentedControl to be displayed
@property (nonatomic, strong) UIImage *normalImageLeft;
@property (nonatomic, strong) UIImage *normalImageMiddle;
@property (nonatomic, strong) UIImage *normalImageRight;
@property (nonatomic, strong) UIImage *selectedImageLeft;
@property (nonatomic, strong) UIImage *selectedImageMiddle;
@property (nonatomic, strong) UIImage *selectedImageRight;

@property (nonatomic, strong) UIFont *buttonFont;
//@property (nonatomic, strong) UIColor *buttonTextColor;
// 存储按钮的文字平时的颜色
//@property (nonatomic, strong) NSMutableArray *buttonTextColorArr;
@property (nonatomic, strong) UIColor *selectedButtonTextColor;
@property (nonatomic, strong) UIColor *buttonShadowColor;
@property (nonatomic, strong) UIColor *selectedButtonShadowColor;
@property (nonatomic) CGSize buttonShadowOffset;

@property (nonatomic, readonly) NSUInteger numberOfSegments;
@property (nonatomic, getter=isMomentary) BOOL momentary; // if set, then we don't keep showing selected state after tracking ends. default is NO

// 不同颜色的分段选择器
@property (nonatomic, strong) NSMutableArray *segmentsColor;

// returns last segment pressed. default is STSegmentedControlNoSegment until a segment is pressed. Becomes STSegmentedControlNoSegment again when altering the amount of segments
// the UIControlEventValueChanged action is invoked when the segment changes via a user event. Set to UISegmentedControlNoSegment to turn off selection
@property (nonatomic, readwrite) NSInteger selectedSegmentIndex;

- (id)initWithItems:(NSArray *)items; // items can be NSStrings or UIImages.

- (void)insertSegmentWithTitle:(NSString *)title atIndex:(NSUInteger)index; // insert before segment number
- (void)insertSegmentWithImage:(NSString *)image atIndex:(NSUInteger)index;
- (void)removeSegmentAtIndex:(NSUInteger)index;
- (void)removeAllSegments;

- (void)setTitle:(NSString *)title forSegmentAtIndex:(NSUInteger)index;
- (NSString *)titleForSegmentAtIndex:(NSUInteger)index;

- (void)setImage:(NSString *)image forSegmentAtIndex:(NSUInteger)index;
- (UIImage *)imageForSegmentAtIndex:(NSUInteger)index;

// 设置字体颜色：color颜色， index：是第几个选择器（0开始）
- (void) setTitleColor:(UIColor *) color forSegmentAtIndex:(NSInteger)index;

@end
