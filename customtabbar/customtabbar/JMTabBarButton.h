//
//  JMTabBarButton.h
//  JMTabBarController
//
//  Created by JM on 2017/12/28.
//  Copyright © 2017年 JM. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "JMConfig.h"

@interface JMTabBarButton : UIView

/** UIImageView */
@property (nonatomic, strong) UIImageView *imageView;
/** Title */
@property (nonatomic, strong) UILabel *title;
/** type */
@property (nonatomic, assign) JMConfigTypeLayout typeLayout;

@end
