#pragma once

class Effect
{
public:
	Effect(ID3D11Device* pDevice, const std::wstring& assetFile);
	~Effect();

	Effect(const Effect&) = delete;
	Effect(Effect&&) noexcept = delete;
	Effect& operator=(const Effect&) = delete;
	Effect& operator=(Effect&&) noexcept = delete;

	ID3DX11Effect* GetEffect();
	ID3DX11EffectTechnique* GetTechnique();

	void SetMatrix(const dae::Matrix& matrix);
private:
	static ID3DX11Effect* LoadEffect(ID3D11Device* pDevice, const std::wstring& assetFile);

	ID3DX11Effect* m_pEffect;
	ID3DX11EffectTechnique* m_pTechnique;
	ID3DX11EffectMatrixVariable* m_pMatWorldViewProjVariable;
};

