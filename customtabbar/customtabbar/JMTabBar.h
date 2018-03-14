//
//  JMTabBar.h
//  JMTabBarController
//
//  Created by JM on 2017/12/27.
//  Copyright © 2017年 JM. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "JMConfig.h"

@class JMTabBar;
@protocol JMTabBarDelegate <NSObject>

- (void)tabBar:(JMTabBar *)tabBar didSelectIndex:(NSInteger)selectIndex;

@end

@interface JMTabBar : UITabBar

- (instancetype)initWithFrame:(CGRect)frame norImageArr:(NSArray *)norImageArr SelImageArr:(NSArray *)selImageArr TitleArr:(NSArray *)titleArr Config:(JMConfig *)config;

/** 代理 */
@property (nonatomic, weak) id <JMTabBarDelegate>myDelegate;

/** selectedIndex (默认为0) */
@property (nonatomic, assign) NSInteger selectedIndex;

@end
