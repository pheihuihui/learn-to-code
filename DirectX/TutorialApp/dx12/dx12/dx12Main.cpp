#include "pch.h"
#include "dx12Main.h"
#include "Common\DirectXHelper.h"

using namespace dx12;
using namespace Windows::Foundation;
using namespace Windows::System::Threading;
using namespace Concurrency;

// https://go.microsoft.com/fwlink/?LinkID=613670&clcid=0x804 �Ͻ����ˡ�DirectX 12 Ӧ�ó���ģ��

// ����Ӧ�ó���ʱ���ز���ʼ��Ӧ�ó����ʲ���
dx12Main::dx12Main() {
	// TODO: �����ҪĬ�ϵĿɱ�ʱ�䲽��ģʽ֮�������ģʽ������ļ�ʱ�����á�
	// ���磬���� 60 FPS �̶�ʱ�䲽�������߼��������:
	/*
	m_timer.SetFixedTimeStep(true);
	m_timer.SetTargetElapsedSeconds(1.0 / 60);
	*/
}

// ��������ʼ����������
void dx12Main::CreateRenderers(const std::shared_ptr<DX::DeviceResources>& deviceResources) {
	// TODO: �����滻ΪӦ�ó������ݵĳ�ʼ����
	m_sceneRenderer = std::unique_ptr<Sample3DSceneRenderer>(new Sample3DSceneRenderer(deviceResources));

	OnWindowSizeChanged();
}

// ÿ֡����һ��Ӧ�ó���״̬��
void dx12Main::Update() {
	// ���³�������
	m_timer.Tick([&]() {
		// TODO: �����滻ΪӦ�ó������ݵĸ��º�����
		m_sceneRenderer->Update(m_timer);
	});
}

// ���ݵ�ǰӦ�ó���״̬���ֵ�ǰ֡��
// ���֡�ѳ��ֲ�����׼������ʾ���򷵻� true��
bool dx12Main::Render() {
	// ���״θ���ǰ�������Գ����κ����ݡ�
	if (m_timer.GetFrameCount() == 0) {
		return false;
	}

	// ���ֳ�������
	// TODO: �����滻ΪӦ�ó������ݵ���Ⱦ������
	return m_sceneRenderer->Render();
}

// �ڴ��ڴ�С����(���磬�豸�������)ʱ����Ӧ�ó���״̬
void dx12Main::OnWindowSizeChanged() {
	// TODO: �����滻ΪӦ�ó������ݵ����С��صĳ�ʼ����
	m_sceneRenderer->CreateWindowSizeDependentResources();
}

// ��Ӧ��֪ͨ��������
void dx12Main::OnSuspending() {
	// TODO: ���������滻ΪӦ�õĹ����߼���

	// �������ڹ������ܻ���ʱ��ֹ�����Ӧ�ã����
	// ��ñ���ʹӦ�ÿ������ж�λ�������������κ�״̬��

	m_sceneRenderer->SaveState();

	// ���Ӧ�ó���ʹ���������´�������Ƶ�ڴ���䣬
	// �뿼���ͷŸ��ڴ���ʹ���ɹ�����Ӧ�ó���ʹ�á�
}

// ��Ӧ��֪ͨ�������ٹ���
void dx12Main::OnResuming() {
	// TODO: ���������滻ΪӦ�õĻָ��߼���
}

// ֪ͨ����������Ҫ�ͷ��豸��Դ��
void dx12Main::OnDeviceRemoved() {
	// TODO: �����κ������Ӧ�ó���������״̬��Ȼ���ͷŲ���
	// ��Ч�ĳ�����������Դ��
	m_sceneRenderer->SaveState();
	m_sceneRenderer = nullptr;
}