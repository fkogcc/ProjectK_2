#pragma once

// コントローラーの入力状態を取得する
namespace Pad2
{
	// パッドの入力状態取得
	void Update();

	// 押し下げ判定
	bool IsPress(int button);
	// トリガー判定
	bool IsTrigger(int button);
	// 離した判定
	bool IsRelase(int button);
}
