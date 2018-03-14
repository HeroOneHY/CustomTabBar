//
//  JMConfig.h
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

//自定义log
#ifdef DEBUG
#define JMLog(...) NSLog(__VA_ARGS__)
#else
#define JMLog(...)
#endif

//随机颜色+RGB颜色+RBGA颜色+16进制颜色
#define kRandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0]

#define kTabBarHeight ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49)

#import <Foundation/Foundation.h>
#import "UIColor+JM.h"
@class JMTabBarController;

/** 布局枚举 */
typedef NS_ENUM(NSInteger, JMConfigTypeLayout) {
    JMConfigTypeLayoutNormal, //默认布局 图片在上 文字在下
    JMConfigTypeLayoutImage,  //只有图片 (图片居中)
};


typedef void (^JMConfigCustomBtnBlock) (UIButton *btn, NSInteger index);

@interface JMConfig : NSObject


/**
 单例模式
 */
+ (instancetype)config;

/**
 * 恢复默认配置 (此选项用于demo工程中,实际开发中请忽略)
 */
- (void)configNormal;

/******************************** tabBar 基本配置 ********************************/

/** 布局类型 (默认是 图片在上, 文字在下) */
@property (nonatomic, assign) JMConfigTypeLayout typeLayout;

/** 标题的默认颜色 (默认为 #808080) */
@property (nonatomic, strong) UIColor *norTitleColor;
/** 标题的选中颜色 (默认为 #d81e06)*/
@property (nonatomic, strong) UIColor *selTitleColor;
/** 图片的size (默认 28*28) */
@property (nonatomic, assign) CGSize imageSize;
/** 标题文字大小 (默认 12.f) */
@property (nonatomic, assign) CGFloat titleFont;
/** 标题的偏移值 (标题距离底部的距离 默认 2.f) */
@property (nonatomic, assign) CGFloat titleOffset;
/** 图片的偏移值 (图片距离顶部的距离 默认 2.f) */
@property (nonatomic, assign) CGFloat imageOffset;

/** tabBar */
/** 是否显示tabBar顶部线条颜色 (默认 YES) */
@property (nonatomic, assign) BOOL isClearTabBarTopLine;
/** tabBar顶部线条颜色 (默认亮灰色) */
@property (nonatomic, strong) UIColor *tabBarTopLineColor;
/** tabBar的背景颜色 (默认白色) */
@property (nonatomic, strong) UIColor *tabBarBackground;



/** tabBarController */
@property (nonatomic, strong) JMTabBarController *tabBarController;


/******************************** 自定义按钮 基本配置 ********************************/

/** btnClickBlock */
@property (nonatomic, weak) JMConfigCustomBtnBlock btnClickBlock;

/**
 添加自定义按钮 (目前只支持自定义按钮, 如果需要自定义view或者对加号按钮有更多需求的请联系我)
 @param btn 自定义btn
 @param index 添加的下标位置
 @param btnClickBlock 按钮点击事件的回调
 */
- (void)addCustomBtn:(UIButton *)btn AtIndex:(NSInteger)index BtnClickBlock:(JMConfigCustomBtnBlock)btnClickBlock;

@end





