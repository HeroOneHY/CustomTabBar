// 
//  JMConfig.m
//  JMTabBarController
//
//  Created by JM on 2018/1/2.
//  Copyright © 2018年 JM. All rights reserved.
//
/*
 .----------------. .----------------.
 | .--------------. | .--------------. |
 | |     _____    | | | ____    ____ | |
 | |    |_   _|   | | ||_   \  /   _|| |
 | |      | |     | | |  |   \/   |  | |
 | |   _  | |     | | |  | |\  /| |  | |
 | |  | |_' |     | | | _| |_\/_| |_ | |
 | |  `.___.'     | | ||_____||_____|| |
 | |              | | |              | |
 | '--------------' | '--------------' |
 '----------------' '----------------'
 github: https://github.com/JunAILiang
 blog: https://www.ljmvip.cn
 */


#import "JMConfig.h"
#import "JMTabBarController.h"
#import "JMTabBarButton.h"
#import "UIView+JM.h"

@implementation JMConfig


static id _instance = nil;

+ (instancetype)config {
    return [[self alloc] init];
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    return _instance;
}

- (instancetype)init {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super init];
        [self configNormal];
    });
    return _instance;
}

- (void)configNormal {
    _norTitleColor = [UIColor colorWithHexString:@"#808080"];
    _selTitleColor = [UIColor colorWithHexString:@"#d81e06"];
    _isClearTabBarTopLine = YES;
    _tabBarTopLineColor = [UIColor lightGrayColor];
    _tabBarBackground = [UIColor whiteColor];
    _typeLayout = JMConfigTypeLayoutNormal;
    _imageSize = CGSizeMake(28, 28);
    _titleFont = 12.f;
    _titleOffset = 2.f;
    _imageOffset = 2.f;
}

- (void)addCustomBtn:(UIButton *)btn AtIndex:(NSInteger)index BtnClickBlock:(JMConfigCustomBtnBlock)btnClickBlock {    
    btn.tag = index;
    [btn addTarget:self action:@selector(customBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    self.btnClickBlock = btnClickBlock;
    [self.tabBarController.JM_TabBar addSubview:btn];
}

- (void)customBtnClick:(UIButton *)sender {
    if (self.btnClickBlock) {
        self.btnClickBlock(sender, sender.tag);
    }
}

- (JMTabBarButton *)getTabBarButtonAtIndex:(NSInteger)index {
    NSArray *subViews = self.tabBarController.JM_TabBar.subviews;
    for (int i = 0; i < subViews.count; i++) {
        UIView *tabBarButton = subViews[i];
        if ([tabBarButton isKindOfClass:[JMTabBarButton class]] && i == index) {
            JMTabBarButton *tabBarBtn = (JMTabBarButton *)tabBarButton;
            return tabBarBtn;
        }
    }
    return nil;
}

- (NSMutableArray *)getTabBarButtons {
    NSArray *subViews = self.tabBarController.JM_TabBar.subviews;
    NSMutableArray *tempArr = [NSMutableArray array];
    for (int i = 0; i < subViews.count; i++) {
        UIView *tabBarButton = subViews[i];
        if ([tabBarButton isKindOfClass:[JMTabBarButton class]]) {
            JMTabBarButton *tabBarBtn = (JMTabBarButton *)tabBarButton;
            [tempArr addObject:tabBarBtn];
        }
    }
    return tempArr;
}

@end
