#include "caffe/layers/loss/smooth_l1_loss_layer.hpp"

namespace caffe {

template <typename Dtype>
void SmoothL1LossLayer<Dtype>::LayerSetUp(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) 
{
	ignore_value = this->layer_param_.loss_param().ignore_label();
}

template <typename Dtype>
void SmoothL1LossLayer<Dtype>::Reshape(const vector<Blob<Dtype>*>& bottom, const vector<Blob<Dtype>*>& top) 
{
	top[0]->Reshape(1,1,1,1);
	
  CHECK_EQ(bottom[0]->channels(), bottom[1]->channels());
  CHECK_EQ(bottom[0]->height(), bottom[1]->height());
  CHECK_EQ(bottom[0]->width(), bottom[1]->width());
  
  loss_.Reshape(bottom[0]->num(),bottom[0]->channels(),bottom[0]->height(),bottom[0]->width());
  counts_.Reshape(bottom[0]->num(),bottom[0]->channels(),bottom[0]->height(),bottom[0]->width());
}


INSTANTIATE_CLASS(SmoothL1LossLayer);
REGISTER_LAYER_CLASS(SmoothL1Loss);

}  // namespace caffe
