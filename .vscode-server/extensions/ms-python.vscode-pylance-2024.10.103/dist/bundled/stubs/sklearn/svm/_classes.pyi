from numbers import Integral as Integral, Real as Real
from typing import Any, Callable, ClassVar, Literal, Mapping, TypeVar

from numpy import ndarray
from numpy.random import RandomState

from .._typing import ArrayLike, Float, Int, MatrixLike
from ..base import BaseEstimator, OutlierMixin, RegressorMixin
from ..linear_model._base import LinearClassifierMixin, LinearModel, SparseCoefMixin
from ..utils import deprecated
from ..utils._param_validation import Interval as Interval, StrOptions as StrOptions
from ..utils.multiclass import check_classification_targets as check_classification_targets
from ._base import BaseLibSVM, BaseSVC

OneClassSVM_Self = TypeVar("OneClassSVM_Self", bound="OneClassSVM")
LinearSVC_Self = TypeVar("LinearSVC_Self", bound="LinearSVC")
LinearSVR_Self = TypeVar("LinearSVR_Self", bound="LinearSVR")

import numpy as np

class LinearSVC(LinearClassifierMixin, SparseCoefMixin, BaseEstimator):
    n_iter_: int = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    classes_: ndarray = ...
    intercept_: ndarray = ...
    coef_: ndarray = ...

    _parameter_constraints: ClassVar[dict] = ...

    def __init__(
        self,
        penalty: Literal["l1", "l2", "l2"] = "l2",
        loss: Literal["squared_hinge", "hinge", "squared_hinge"] = "squared_hinge",
        *,
        dual: bool = True,
        tol: Float = 1e-4,
        C: Float = 1.0,
        multi_class: Literal["ovr", "crammer_singer", "ovr"] = "ovr",
        fit_intercept: bool = True,
        intercept_scaling: Float = 1,
        class_weight: None | Mapping | str = None,
        verbose: Int = 0,
        random_state: RandomState | None | Int = None,
        max_iter: Int = 1000,
    ) -> None: ...
    def fit(
        self: LinearSVC_Self,
        X: MatrixLike | ArrayLike,
        y: ArrayLike,
        sample_weight: None | ArrayLike = None,
    ) -> LinearSVC_Self: ...

class LinearSVR(RegressorMixin, LinearModel):
    n_iter_: int = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    coef_: ndarray = ...

    _parameter_constraints: ClassVar[dict] = ...

    def __init__(
        self,
        *,
        epsilon: Float = 0.0,
        tol: Float = 1e-4,
        C: Float = 1.0,
        loss: Literal["epsilon_insensitive", "squared_epsilon_insensitive", "epsilon_insensitive"] = "epsilon_insensitive",
        fit_intercept: bool = True,
        intercept_scaling: Float = 1.0,
        dual: bool = True,
        verbose: Int = 0,
        random_state: RandomState | None | Int = None,
        max_iter: Int = 1000,
    ) -> None: ...
    def fit(
        self: LinearSVR_Self,
        X: MatrixLike | ArrayLike,
        y: ArrayLike,
        sample_weight: None | ArrayLike = None,
    ) -> LinearSVR_Self: ...

class SVC(BaseSVC):
    shape_fit_: tuple = ...
    probB_: ndarray = ...
    probA_: ndarray = ...
    n_support_: ndarray = ...
    support_vectors_: ndarray = ...
    support_: ndarray = ...
    n_iter_: ndarray = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    fit_status_: int = ...
    dual_coef_: ndarray = ...
    coef_: ndarray = ...
    classes_: ndarray = ...
    class_weight_: ndarray = ...

    _impl: ClassVar[str] = ...

    def __init__(
        self,
        *,
        C: Float = 1.0,
        kernel: Literal["linear", "poly", "rbf", "sigmoid", "precomputed", "rbf"] | Callable = "rbf",
        degree: Int = 3,
        gamma: float | Literal["scale", "auto", "scale"] = "scale",
        coef0: Float = 0.0,
        shrinking: bool = True,
        probability: bool = False,
        tol: Float = 1e-3,
        cache_size: Float = 200,
        class_weight: None | Mapping | str = None,
        verbose: bool = False,
        max_iter: Int = ...,
        decision_function_shape: Literal["ovo", "ovr", "ovr"] = "ovr",
        break_ties: bool = False,
        random_state: RandomState | None | Int = None,
    ) -> None: ...

class NuSVC(BaseSVC):
    shape_fit_: tuple = ...
    probB_: ndarray = ...
    probA_: ndarray = ...
    n_support_: ndarray = ...
    support_vectors_: ndarray = ...
    support_: ndarray = ...
    n_iter_: ndarray = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    fit_status_: int = ...
    dual_coef_: ndarray = ...
    coef_: ndarray = ...
    classes_: ndarray = ...
    class_weight_: ndarray = ...

    _impl: ClassVar[str] = ...

    _parameter_constraints: ClassVar[dict] = ...

    def __init__(
        self,
        *,
        nu: Float = 0.5,
        kernel: Literal["linear", "poly", "rbf", "sigmoid", "precomputed", "rbf"] | Callable = "rbf",
        degree: Int = 3,
        gamma: float | Literal["scale", "auto", "scale"] = "scale",
        coef0: Float = 0.0,
        shrinking: bool = True,
        probability: bool = False,
        tol: Float = 1e-3,
        cache_size: Float = 200,
        class_weight: None | Mapping | str = None,
        verbose: bool = False,
        max_iter: Int = ...,
        decision_function_shape: Literal["ovo", "ovr", "ovr"] = "ovr",
        break_ties: bool = False,
        random_state: RandomState | None | Int = None,
    ) -> None: ...

class SVR(RegressorMixin, BaseLibSVM):
    support_vectors_: ndarray = ...
    support_: ndarray = ...
    shape_fit_: tuple = ...
    n_support_: ndarray = ...
    n_iter_: int = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    fit_status_: int = ...
    dual_coef_: ndarray = ...
    coef_: ndarray = ...

    _impl: ClassVar[str] = ...

    _parameter_constraints: ClassVar[dict] = ...
    for unused_param in ["class_weight", "nu", "probability", "random_state"]:
        pass

    def __init__(
        self,
        *,
        kernel: Literal["linear", "poly", "rbf", "sigmoid", "precomputed", "rbf"] | Callable = "rbf",
        degree: Int = 3,
        gamma: float | Literal["scale", "auto", "scale"] = "scale",
        coef0: Float = 0.0,
        tol: Float = 1e-3,
        C: Float = 1.0,
        epsilon: Float = 0.1,
        shrinking: bool = True,
        cache_size: Float = 200,
        verbose: bool = False,
        max_iter: Int = ...,
    ) -> None: ...

    # TODO(1.4): Remove
    @deprecated("Attribute `class_weight_` was deprecated in version 1.2 and will be removed in" " 1.4.")  # type: ignore
    @property
    def class_weight_(self) -> ndarray: ...

class NuSVR(RegressorMixin, BaseLibSVM):
    support_vectors_: ndarray = ...
    support_: ndarray = ...
    shape_fit_: tuple = ...
    n_support_: ndarray = ...
    n_iter_: int = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    fit_status_: int = ...
    dual_coef_: ndarray = ...
    coef_: ndarray = ...

    _impl: ClassVar[str] = ...

    _parameter_constraints: ClassVar[dict] = ...
    for unused_param in ["class_weight", "epsilon", "probability", "random_state"]:
        pass

    def __init__(
        self,
        *,
        nu: Float = 0.5,
        C: Float = 1.0,
        kernel: Literal["linear", "poly", "rbf", "sigmoid", "precomputed", "rbf"] | Callable = "rbf",
        degree: Int = 3,
        gamma: float | Literal["scale", "auto", "scale"] = "scale",
        coef0: Float = 0.0,
        shrinking: bool = True,
        tol: Float = 1e-3,
        cache_size: Float = 200,
        verbose: bool = False,
        max_iter: Int = ...,
    ) -> None: ...

    # TODO(1.4): Remove
    @deprecated("Attribute `class_weight_` was deprecated in version 1.2 and will be removed in" " 1.4.")  # type: ignore
    @property
    def class_weight_(self) -> ndarray: ...

class OneClassSVM(OutlierMixin, BaseLibSVM):
    support_vectors_: ndarray = ...
    support_: ndarray = ...
    shape_fit_: tuple = ...
    offset_: float = ...
    n_support_: ndarray = ...
    n_iter_: int = ...
    feature_names_in_: ndarray = ...
    n_features_in_: int = ...
    intercept_: ndarray = ...
    fit_status_: int = ...
    dual_coef_: ndarray = ...
    coef_: ndarray = ...

    _impl: ClassVar[str] = ...

    _parameter_constraints: ClassVar[dict] = ...
    for unused_param in ["C", "class_weight", "epsilon", "probability", "random_state"]:
        pass

    def __init__(
        self,
        *,
        kernel: Literal["linear", "poly", "rbf", "sigmoid", "precomputed", "rbf"] | Callable = "rbf",
        degree: Int = 3,
        gamma: float | Literal["scale", "auto", "scale"] = "scale",
        coef0: Float = 0.0,
        tol: Float = 1e-3,
        nu: Float = 0.5,
        shrinking: bool = True,
        cache_size: Float = 200,
        verbose: bool = False,
        max_iter: Int = ...,
    ) -> None: ...

    # TODO(1.4): Remove
    @deprecated("Attribute `class_weight_` was deprecated in version 1.2 and will be removed in" " 1.4.")  # type: ignore
    @property
    def class_weight_(self) -> ndarray: ...
    def fit(
        self: OneClassSVM_Self,
        X: MatrixLike | ArrayLike,
        y: Any = None,
        sample_weight: None | ArrayLike = None,
    ) -> OneClassSVM_Self: ...
    def decision_function(self, X: MatrixLike) -> ndarray: ...
    def score_samples(self, X: MatrixLike) -> ndarray: ...
    def predict(self, X: MatrixLike) -> ndarray: ...
